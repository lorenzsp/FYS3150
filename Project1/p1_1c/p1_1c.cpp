#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cmath> //libreria migliore
#include "time.h"
#include "C:\Users\Davide\Documents\GitHub\FYS3150\Project1\p1_1b\alloc.h"
using namespace std;
//ofstream ofile;
double solution(double x){return 1.0-(1.0-exp(-10))*x-exp(-10*x);};
double f(double x){return 100*exp(-10*x);};


int main(int argc, char* argv[]){
    //for(n=10;n<=10^7;n=n*10){
    int n=atoi(argv[1]);

    //dichiaro tutte le variabili e le allocco con la funzione alloc:
    int* a=alloc(n+1);
    int* b=alloc(n+1);
    int* c=alloc(n+1);
    double* x;
    x=new double [n+2];
    double* s; //sol anal
    s=new double [n+2];
    double* ff; //sorgente
    ff=new double [n+1];

    double h=1.0/(n+1.0); //passi

    int i; //indici
    int j;

//    clock_t t[n];
//    t[n]=clock();

    //analytical solution
    /*La calcolo e la guardo*/
    for (i=0; i<=n+1; i++){
        x[i]=i*h;
        //cout << "x"<<i<<":"<<x[i]<< endl;
    }

    for (i=0;i<=n+1; i++){
        s[i]=solution(x[i]);
            if(i==n+1){s[i]=0;}
        cout << "s"<<i<<":"<<s[i]<< endl; //é quello che mi aspetto!
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
    double* ff_t;
    ff_t= new double [n+1];
    double* b_t;
    b_t=new double [n+1];
    double* ss;
    ss=new double [n+2];

    b_t[0]=0;
    b_t[1]=b[1];
    ff_t[0]=0;
    ff_t[1]=ff[1];
    for(i=2;i<=n; i++){
        b_t[i]=b[i]-(a[i-1]*a[i-1])/(b_t[i-1]); //coeff con tilda
        ff_t[i]=ff[i]-a[i-1]*ff_t[i-1]/(b_t[i-1]); //sorgente con tilda
    }
    for(i=1;i<=n;i++){
//    cout << "b_t"<<i<<":"<<b_t[i]<< endl;
//    cout << "ff"<<i<<":"<<ff[i]<< endl;
//   cout << "ff_t"<<i<<":"<<ff_t[i]<< endl;
    }

    //backward subst
        ss[0]=ss[n+1]=0;
        ss[n]=ff_t[n]/b_t[n];
    for(j=n-1;j>0; j--){
            ss[j]=(ff_t[j] -a[j]*ss[j+1])/(b_t[j]);

    }

    for(i=0; i<=n+1;i++){
        cout << "ss"<<i<<"="<<ss[i]<< endl;
    }

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

    delete [] ss;
    delete [] s;
    delete [] a;
    delete [] b;
    delete [] b_t;
    delete [] c;
    delete [] ff;
    delete [] ff_t;

    //errors
    double* err;
    err=new double [n];

     for(i=1;i<=n;i++){
     err[i]=log10(abs((ss[i]-s[i])/(s[i])));
     err[i]=abs(err[i]);
     cout << err[i] << endl;
    }
     //trovo il massimo
     double max_err=err[1]; //questo diventerà una matrice e per ogni n metterò il massimo
     for (i = 1;i <=n;i++);

         {
             if (err[i] > max_err)
                 max_err = err[i];
         }
     cout << max_err << endl;
     //}
return 0;
}

