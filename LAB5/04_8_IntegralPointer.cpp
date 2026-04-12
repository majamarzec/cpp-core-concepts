#include <iostream>
#include <cmath>
using namespace std;


double Fun (double x) {
    return sin(x);
}

double Integral ( double (*MyFunPtr) (double), double x0, double x1, int Nsteps) {

    double xDelta = (x1 - x0)/ Nsteps;
    double integralValue = 0, constValue = (MyFunPtr(x0) + MyFunPtr(x1)) / 2 ;
    for (double i = x0; i <= x1; i += xDelta){
        integralValue += (MyFunPtr(i - xDelta) + MyFunPtr(i)) / 2 *  xDelta;
    }
    return integralValue;   
}


int main() {
    double a = 0., b = M_PI, Nsteps = 1000;
    cout << "Wynik całki: " << Integral (tanh, a, b, Nsteps) << endl;
}