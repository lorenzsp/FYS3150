#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include "time.h"
#include <armadillo>
#include <string.h>

using namespace std;
using namespace arma;

// ofstream ofile;
double solution(double x){return 1.0-(1.0-exp(-10))*x-exp(-10*x);};
double f(double x){return 100*exp(-10*x);};

int main(int argc, char* argv[]){

    int n=atoi(argv[1]);
    if (argc<=1){
        cout <<"You forgot something, watch out: you have to write the output file and n (int), size of vectors on same line." << endl;
        exit(1);
    }

    //Declaration and allocation of variables with Armadillo
    vec a=randu<vec>(1,n+1);
    vec b=randu<vec>(1,n+1);
    vec c=randu<vec>(1,n+1);
    vec x=randu<vec>(1,n+2);
    vec u=randu<vec>(1,n+2);
    vec r=randu<vec>(1,n+1);

    double h=1.0/(n+1.0); //number of steps

    int i; //indexes
    int j;

    //time calculation
    clock_t t;
    t=clock();

    //analytical solution
    for (i=0; i<=n+1; i++){
        x[i]=i*h;
        //cout << "x"<<i<<":"<<x[i]<< endl; /*print steps/*
    }

    for (i=0;i<=n+1; i++){
        u[i]=solution(x[i]);
            if(i==n+1){u[i]=0;}
       // cout << "u"<<i<<":"<<u[i]<< endl; /*print analytical solution/*
    }

    //numerical solution
     for (i=1; i<=n; i++){
        r[i]=h*h*f(x[i]); /*arranging the right side of equation -u''=f(x)*/
    }

    /*Filling a,b,c*/
    b[0]=a[0]=c[0]=0; /* si I start with index 1 */
    for (i=1;i<=n;i++){
        if(i==1){
            int bb, aa, cc;
            cout << "b[i]=" <<endl;
            cin >> bb;
            b[i]=bb;
            cout << "a[i]=" <<endl;
            cin >> aa;
            a[i]=aa;
            cout << "c[i]=" <<endl;
            cin >> cc;
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
//       cout << "b"<<i<<":"<<b[i]<< endl;
//       cout << "a"<<i<<":"<<a[i]<< endl;
//       cout << "c"<<i<<":"<<c[i]<< endl;
    }

    //forward substitution
    /*Declaring vectors*/
    vec r_t=randu<vec>(n+1); /*vectors with _t represents tilde vectors*/
    vec b_t=randu<vec>(n+1);
    vec v=randu<vec>(n+2);

    b_t[0]=0;
    b_t[1]=b[1];
    r_t[0]=0;
    r_t[1]=ff[1];
    for(i=2;i<=n; i++){
        b_t[i]=b[i]-(a[i-1]*a[i-1])/(b_t[i-1]);
        r_t[i]=r[i]-a[i-1]*r_t[i-1]/(b_t[i-1]);
    }
    for(i=1;i<=n;i++){
//    cout << "b_t"<<i<<":"<<b_t[i]<< endl;
//    cout << "r"<<i<<":"<<r[i]<< endl;
//   cout << "r_t"<<i<<":"<<r_t[i]<< endl;
    }

    //backward substitution
        v[0]=v[n+1]=0;
        v[n]=r_t[n]/b_t[n];
    for(i=n-1;i>0; i--){
            v[i]=(r_t[i] -a[i]*v[i+1])/(b_t[i]);

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

    // Finishing clock and printing the time needed
    t=clock()-t;
    cout << "the programme took " <<(float) t/CLOCKS_PER_SEC<< " seconds" << endl;

return 0;
}

