#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cmath> //libreria migliore
#include "time.h"
#define ARMA_USE_LAPACK
#define ARMA_USE_BLAS

#include <armadillo>

using namespace std;
using namespace arma;

double f(double x){return 100*exp(-10*x);};

int main(int argc, char* argv[])
{

     int n=atoi(argv[1]);
     if (argc<=1){
        cout <<"You forgot something, watch out: you have to write the output file and n (int), size of vectors on same line." << endl;
        exit(1);
        }

    //dichiaro tutte le variabili:
    mat A=zeros<mat>(n+2,n+2);
    vec a=randu<vec>(n+1);
    vec b=randu<vec>(n+1);
    vec c=randu<vec>(n+1);

    //    clock_t t[n];
    //    t[n]=clock();

    double h=1.0/(n+1.0); //passi
    int i,j;

    //definisco A
    for(i=1;i<=n+1;i++){
        for(j=1;j<=n+1;j++){
            if(i==j){
                A(i,j)=2.0;
            } else if (j==i+1||(i>=2&&j==i-1)){
                A(i,j)=-1.0;
            } else  {
                A(i,j)=0.0;
            }
        }
    }
    //A.print();

    vec x=randu<vec>(n+2);
    //vec u=randu<vec>(n+2);
    vec r=randu<vec>(n+2);

    //numericall solution
    for (i=0; i<=n+1; i++){
        x[i]=i*h;
        cout << "x"<<i<<":"<<x[i]<< endl;
    }

//    for (i=0;i<=n+1; i++){
//        u[i]=solution(x[i]);
//            if(i==n+1){u[i]=0;}
//        //cout << "u"<<i<<":"<<u[i]<< endl; //é quello che mi aspetto!
//    }

    //numerical solution
    /*sistemo la sorgente*/
     for (i=0; i<=n+1; i++){
        r[i]=h*h*f(x[i]);
    }

    vec v=solve(A,r);
    cout << v << endl;

    //    t[n]=(float) (clock()-t[n])/CLOCKS_PER_SEC;
    //    cout << "the programme took " << t[n]<< " seconds" << endl;

    return 0;
}
