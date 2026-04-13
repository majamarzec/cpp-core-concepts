#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


double dXdt (double t){
    return cos(t);
}


double dYdt (double t){
    return -sin(t);
}

double PathLength (double t1, double t2, double dt){
    double Integral = 0.;
    for (double temp = t1; temp <= t2; temp += dt){
        Integral += sqrt (pow( dXdt (temp), 2) + pow( dYdt (temp), 2) ) * dt;
    }
    return Integral / M_PI ;
}

int main(){

    double t1 = -M_PI/ 2,  t2 = M_PI/ 2, dt = 1e-5;
    cout << "Dlugosc drogi: " << PathLength(t1, t2, dt) << " pi" << endl;
}