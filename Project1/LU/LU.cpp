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

     int n=atoi(argv[2]);
     if (argc<=2){
        cout <<"You forgot something, watch out: you have to write the output file and n (int), size of vectors on same line." << endl;
        exit(1);
        }

    //dichiaro tutte le variabili:
    mat A=randu<mat>(n,n);
    vec a=randu<vec>(n+1);
    vec b=randu<vec>(n+1);
    vec c=randu<vec>(n+1);

    double h=1.0/(n+1.0); //passi
    int i,j;

    //definisco A
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                A(i,j)=2;
            } else if (j==i+1||(i>=1&&j==i-1)){
                A(i,j)=-1;
            } else  {
                A(i,j)=0;
            }
        }
    }
    A.print();

    vec x=randu<vec>(n);
    vec s=randu<vec>(n);
    vec ff=randu<vec>(n);

    //analytical solution
    for (i=0; i<n; i++){
        x[i]=i*h;
        //cout << "x"<<i<<":"<<x[i]<< endl;
    }

//    for (i=0;i<=n+1; i++){
//        s[i]=solution(x[i]);
//            if(i==n+1){s[i]=0;}
//        //cout << "s"<<i<<":"<<s[i]<< endl; //é quello che mi aspetto!
//    }

    //numerical solution
    /*sistemo la sorgente*/
     for (i=0; i<n; i++){
        ff[i]=h*h*f(x[i]);
    }

    vec ss=solve(A,ff);
    ss.print();
    return 0;
}
