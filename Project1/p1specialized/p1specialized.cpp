#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cmath> //libreria migliore
#include "time.h"
#include <armadillo>

using namespace std;
using namespace arma;


ofstream ofile; /*print to file*/

// functions used
double solution(double x){return 1.0-(1.0-exp(-10))*x-exp(-10*x);};
double f(double x){return 100*exp(-10*x);};


int main(int argc, char* argv[]){
   int n=atoi(argv[1]);
   int ii;
   int q=atoi(argv[2]);
   //mat max_err(q,3);
   mat time(q,2);
   if (argc<=1){
            cout <<"You forgot something, watch out: you have to write the output file and n (int), size of vectors on same line." << endl;
            exit(1);
            }
    for(ii=0;ii<=q-1;ii++){


    //Declaration and allocation of variables with Armadillo

    vec x(n+2);
    vec u(n+2);
    u[n+1]=0;
    vec r(n+1);
    vec r_t(n+1); /*vectors with _t represents tilde vectors*/
    r_t[0]=0;
    vec b_t(n+1);
    b_t[0]=0;
    b_t[1]=2;
    vec v(n+2);
    v[0]=v[n+1]=0;


    double h=1.0/(n+1.0); //number of steps

    int i; //index

    // time calculation
    clock_t t;
    t=clock();

    //analytical solution
    for (i=0; i<=n+1; i++){
        x[i]=i*h;
        //cout << "x"<<i<<":"<<x[i]<< endl; /*print steps*/
    }

    for (i=0;i<n+1; i++){
        u[i]=solution(x[i]);
        //cout << "u"<<i<<":"<<u[i]<< endl;  /*print analytical solution*/
    }

    //numerical solution
     for (i=1; i<=n; i++){
        r[i]=h*h*f(x[i]); /*arranging the right side of equation -u''=r(x)=h^2*f(x)*/
    }

//     /*Filling a,b,c*/
//     b[0]=a[0]=c[0]=0;
//     b[n]=2;
//     a[n]=c[n]=0;/* si I start with index 1 */
//    for (i=1;i<n;i++){
//            b[i]=2;
//            a[i]=-1;
//            c[i]=-1;
//        }
//       cout << "b"<<i<<":"<<b[i]<< endl;
//       cout << "a"<<i<<":"<<a[i]<< endl;
//       cout << "c"<<i<<":"<<c[i]<< endl;

    //Forward
    /*Declaring vectors*/

    r_t[1]=r[1];
    for(i=2;i<=n; i++){
        b_t[i]=(i+1.0)/i;
        r_t[i]=r[i]+(i-1.0)*r_t[i-1]/(i);
    }
    //for(i=1;i<=n;i++){
//      cout << "b_t"<<i<<":"<<b_t[i]<< endl;
//      cout << "r"<<i<<":"<<r[i]<< endl;
//      cout << "r_t"<<i<<":"<<r_t[i]<< endl;
    //}

    //backward substitution


    v[n]=r_t[n]/b_t[n];
    for(i=n-1;i>0; i--){
                v[i]=(r_t[i]+v[i+1])*i/(i+1);
    }
//    for(i=0; i<=n+1;i++){
//       cout << "v"<<i<<"="<<v[i]<< endl; /*print numerical solution*/
//    }

    //computing relative errors
//    int k;
//    double *err=new double [n];
//    //double *err = new double [n];
//    for(k=0;k<n;k++){
//     err[k]= log10(abs((v[k+1]-u[k+1])/(u[k+1])));
//    }
//     //err.print();

//   /*defining a matrix
//                                   *with 1 row 3 columns:
//                     * n/log10(h)/max relative error */

//        max_err(ii,0)=n;
//    //max_err(0,1)=log10(h);
//    double MAX=err[0];
//        for(k=1;k<n;k++){
//            if(err[k]>MAX)
//                MAX=err[k];
//        }
//        max_err(ii,1)=log10(h);
//        max_err(ii,2)=MAX;
//    //max_err.print();

//    delete [] err;
            time(ii,0)=n;
            time(ii,1)=(float) (clock()-t)/CLOCKS_PER_SEC;



         n = 10*n;
  }


//     // Open file and write results to file:
//     ofile.open("dat_p1_1000.txt");
//     ofile << setiosflags(ios::showpoint | ios::uppercase);
//     ofile << " x: u(x): v(x): " << endl;
//     for (int i=0;i<=n+1;i++) {
//     ofile << setw(15) << setprecision(8) << u[i];
//     ofile << setw(15) << setprecision(8) << v[i] << endl;
//     }
//  ofile.close();

         // Open file and write results to file:
         ofile.open("time_particular.txt");
         ofile << setiosflags(ios::showpoint | ios::uppercase);
         ofile << " n:          time: " << endl;
         for (int i=0;i<=q-1;i++) {
         ofile << setw(15) << setprecision(8) << time(i,0);
         ofile << setw(15) << setprecision(8) << time(i,1) << endl;
         }
      ofile.close();
   time.print();

return 0;
}

