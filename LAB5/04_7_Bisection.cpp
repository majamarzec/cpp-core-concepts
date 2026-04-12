#include <cmath>
#include <limits>
#include <iomanip> // tu jest setprecision
#include <iostream>
using namespace std;

double myfun (double x) {
  return exp(-x) - x;
}

// wskaznik funkcyjny (double (*MyFun) (double)

double Bisection (double (*MyFun) (double), double a, double b, double eps) {
  double fa = MyFun(a) , fb = MyFun(b) , xc ;
  do {
    xc = ( a + b ) / 2. ;
    if (MyFun (a) * MyFun (xc) < 0 ) {
      b = xc ;
    } else { 
      a = xc;
    }
  } while ( fabs(b - a) > eps );
  return (a + b) / 2. ;
}

int main () {
  cout << setprecision ( numeric_limits<double>::max_digits10 )
        << Bisection (myfun, 0.,1. , numeric_limits<double>::epsilon() )
        << endl;
}
