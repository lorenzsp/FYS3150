#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cmath> //libreria migliore
#include "time.h"
#include <armadillo>

using namespace std;
using namespace arma;

//ofstream ofile;
double solution(double x){return 1.0-(1.0-exp(-10))*x-exp(-10*x);};
double f(double x){return 100*exp(-10*x);};


int main(int argc, char* argv[]){

     int n=atoi(argv[1]);
     if (argc<=1){
        cout <<"You forgot something, watch out: you have to write the output file and n (int), size of vectors on same line." << endl;
        exit(1);
        }

    //dichiaro tutte le variabili e le allocco con la funzione alloc:
    vec a=randu<vec>(n+1);
    vec b=randu<vec>(n+1);
    vec c=randu<vec>(n+1);
    vec x=randu<vec>(n+2);
    vec u=randu<vec>(n+2);
    vec r=randu<vec>(n+1);

    double h=1.0/(n+1.0); //passi

    int i; //indici
    int j;

//    clock_t t;
//    t=clock();

    //analytical solution
    for (i=0; i<=n+1; i++){
        x[i]=i*h;
        cout << "x"<<i<<":"<<x[i]<< endl;
    }

    for (i=0;i<=n+1; i++){
        u[i]=solution(x[i]);
            if(i==n+1){u[i]=0;}
        cout << "s"<<i<<":"<<u[i]<< endl; //é quello che mi aspetto!
    }

    //numerical solution
    /*sistemo la sorgente*/
     for (i=1; i<=n; i++){
        r[i]=h*h*f(x[i]);
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
    vec r_t=randu<vec>(n+1,1);
    vec b_t=randu<vec>(n+1,1);
    vec v=randu<vec>(n+2,1);

    b_t[0]=0;
    b_t[1]=b[1];
    r_t[0]=0;
    r_t[1]=ff[1];
    for(i=2;i<=n; i++){
        b_t[i]=b[i]-(a[i-1]*a[i-1])/(b_t[i-1]); //coeff con tilda
        r_t[i]=r[i]-a[i-1]*r_t[i-1]/(b_t[i-1]); //sorgente con tilda
    }
    //for(i=1;i<=n;i++){
//    cout << "b_t"<<i<<":"<<b_t[i]<< endl;
//    cout << "ff"<<i<<":"<<ff[i]<< endl;
//   cout << "ff_t"<<i<<":"<<ff_t[i]<< endl;
    //}

    //backward subst
        v[0]=v[n+1]=0;
        r[n]=r_t[n]/b_t[n];
    for(j=n-1;j>0; j--){
            v[j]=(ff_t[j] -a[j]*v[j+1])/(b_t[j]);

    }

    for(i=0; i<=n+1;i++){
       cout << "v"<<i<<"="<<v[i]<< endl;
    }

    // Open file and write results to file:
//    ofile.open("dat_p1_1000.txt");
//    ofile << setiosflags(ios::showpoint | ios::uppercase);
//    ofile << " x: u(x): v(x): " << endl;
//    for (int i=0;i<=n+1;i++) {
//    ofile << setw(15) << setprecision(8) << x[i];
//    ofile << setw(15) << setprecision(8) << u[i];
//    ofile << setw(15) << setprecision(8) << v[i] << endl;
//    }
//    ofile.close();

//    t[n]=(float) (clock()-t[n])/CLOCKS_PER_SEC;
//    cout << "the programme took " << t[n]<< " seconds" << endl;

    //errors
//    int k;
//    vec err=randu<vec>(n);
//    for(k=0;k<n;k++){
//     err[k]=log10(abs((v[k+1]-u[k+1])/(u[k+1])));
//     //err[i]=abs(err[i]);
//    }
//     //err.print();

//    mat max_err=randu<mat>(1,3);

//     //Matrix with 1 row 3 columns: n/log10(h)/max error
//     max_err(0,0)=n;
//     max_err(0,1)=log10(h);
//     max_err(0,2)=min(err);
//     max_err.print();
return 0;
}

