#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cmath> //libreria migliore
#include "time.h"
#include <armadillo>

using namespace std;
using namespace arma;

//function used
double f(double x){return 100*exp(-10*x);};

int main(int argc, char* argv[])
{

     int n=atoi(argv[1]);
     if (argc<=1){
        cout <<"You forgot something, watch out: you have to write the output file and n (int), size of vectors on same line." << endl;
        exit(1);
        }

    //Declaration and allocation of variables with Armadillo
    mat A=zeros<mat>(n+2,n+2);
    mat C=randu<mat>(n+2,n+2);
    vec x=randu<vec>(n+2);
    vec r=randu<vec>(n+2);

    double h=1.0/(n+1.0); //number of steps

    int i,j; //indexes

    //time calculation
    //    clock_t t[n];
    //    t[n]=clock();

    //filling the tridiagonal matrix A
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
    //A.print(); /*print to check*/

    //numerical solution
    for (i=0; i<=n+1; i++){
        x[i]=i*h;
        r[i]=h*h*f(x[i]); /*arranging the right side of equation -u''=r(x)=h^2*f(x)*/
        cout << "x"<<i<<":"<<x[i]<< endl;
    }

    //vec v=solve(A,r); /*numerical solution with LU, and I print it*/
    //cout << v << endl;
    cout <<A*C<< endl;
mat B=A.i();
B.print();

    // Finishing clock and printing the time needed
    //    t[n]=(float) (clock()-t[n])/CLOCKS_PER_SEC;
    //    cout << "the programme took " << t[n]<< " seconds" << endl;

    return 0;
}
