#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cmath> //libreria migliore
#include "time.h"
#include "C:\Users\Davide\Documents\GitHub\FYS3150\Project1\p1_1b\alloc.h"
#include <armadillo>

using namespace std;
using namespace arma;

//ofstream ofile;
double solution(double x){return 1.0-(1.0-exp(-10))*x-exp(-10*x);};
double f(double x){return 100*exp(-10*x);};


int main(int argc, char* argv[]){

     int n=atoi(argv[2]);
     if (argc<=2){
        cout <<"You forgot something, watch out: you have to write the output file and n (int), size of vectors on same line." << endl;
        exit(1);
        }

    //dichiaro tutte le variabili e le allocco con la funzione alloc:
    vec a=randu<vec>(n+1);
    vec b=randu<vec>(n+1);
    vec c=randu<vec>(n+1);
    vec x=randu<vec>(n+2);
    vec s=randu<vec>(n+2);
    vec ff=randu<vec>(n+1);

    double h=1.0/(n+1.0); //passi

    int i; //indici
    int j;

//    clock_t t[n];
//    t[n]=clock();

    //analytical solution
    for (i=0; i<=n+1; i++){
        x[i]=i*h;
        //cout << "x"<<i<<":"<<x[i]<< endl;
    }

    for (i=0;i<=n+1; i++){
        s[i]=solution(x[i]);
            if(i==n+1){s[i]=0;}
        //cout << "s"<<i<<":"<<s[i]<< endl; //é quello che mi aspetto!
    }

    //numerical solution
    /*sistemo la sorgente*/
     for (i=1; i<=n; i++){
        ff[i]=h*h*f(x[i]);
    }
    /*Riempio a,b,c*/
    b[0]=a[0]=c[0]=0; /* così parto da indice 1 */
    for (i=1;i<=n;i++){
        if(i==1){
            int bb=2;
            int aa=-1;
            int cc=-1;
            b[i]=bb;
            a[i]=aa;
            c[i]=cc;
        } else if(i==n) {
            b[i]=b[i-1];
            a[i]=0;
            c[i]=0;
        } else {
            b[i]=b[i-1];
            a[i]=a[i-1];
            c[i]=c[i-1];
        }
//        cout << "b"<<i<<":"<<b[i]<< endl;
//        cout << "a"<<i<<":"<<a[i]<< endl;
//       cout << "c"<<i<<":"<<c[i]<< endl;
    }

    //forward subst
    vec ff_t=randu<vec>(n+1,1);
    vec b_t=randu<vec>(n+1,1);
    vec ss=randu<vec>(n+2,1);

    b_t[0]=0;
    b_t[1]=b[1];
    ff_t[0]=0;
    ff_t[1]=ff[1];
    for(i=2;i<=n; i++){
        b_t[i]=b[i]-(a[i-1]*a[i-1])/(b_t[i-1]); //coeff con tilda
        ff_t[i]=ff[i]-a[i-1]*ff_t[i-1]/(b_t[i-1]); //sorgente con tilda
    }
    //for(i=1;i<=n;i++){
//    cout << "b_t"<<i<<":"<<b_t[i]<< endl;
//    cout << "ff"<<i<<":"<<ff[i]<< endl;
//   cout << "ff_t"<<i<<":"<<ff_t[i]<< endl;
    //}

    //backward subst
        ss[0]=ss[n+1]=0;
        ss[n]=ff_t[n]/b_t[n];
    for(j=n-1;j>0; j--){
            ss[j]=(ff_t[j] -a[j]*ss[j+1])/(b_t[j]);

    }

    //for(i=0; i<=n+1;i++){
       // cout << "ss"<<i<<"="<<ss[i]<< endl;
    //}

    // Open file and write results to file:
//    ofile.open("dat_p1_1000.txt");
//    ofile << setiosflags(ios::showpoint | ios::uppercase);
//    ofile << " x: s(x): ss(x): " << endl;
//    for (int i=0;i<=n+1;i++) {
//    ofile << setw(15) << setprecision(8) << x[i];
//    ofile << setw(15) << setprecision(8) << s[i];
//    ofile << setw(15) << setprecision(8) << ss[i] << endl;
//    }
//    ofile.close();

//    t[n]=(float) (clock()-t[n])/CLOCKS_PER_SEC;
//    cout << "the programme took " << t[n]<< " seconds" << endl;

    //errors
    int k;
    vec err=randu<vec>(n);
    for(k=0;k<n;k++){
     err[k]=log10(abs((ss[k+1]-s[k+1])/(s[k+1])));
     //err[i]=abs(err[i]);
    }
     //err.print();

    mat max_err=randu<mat>(1,3);

     //Matrix with 1 row 3 columns: n/log10(h)/max error
     max_err(0,0)=n;
     max_err(0,1)=log10(h);
     max_err(0,2)=min(err);
     max_err.print();
return 0;
}

