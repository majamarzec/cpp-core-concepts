#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double f (double x, double y){

    double A, B, C;

    if (x == 1){
        cout << "Wyjątek!";
        A = 1;
    }

    else A = sin(x - 1) / (x - 1);

    B = cos(y);
    C = 1 + y/10;

    return A * B * C;
}

double fPrim (double x, double y, double step){
    return (f(x, y) - f(x - step, y - step))/step;
}

void Analiza (double (*MyFunPtr) (double), double a, double b, double step, double* Xmin, double* Ymin, double* Zmin){

    for (double i = a; i <= b; i+= step){

        double Z = MyFunPtr(i); 

        if (Z < *Zmin) {
            *Zmin = Z;
            *Xmin = i;
            *Ymin = i;}
        }
    
    cout << "Analiza zakonczona!" << endl;  
}

int main(){

    double a = -5., b = 5., step = 0.005;
    double Xmin = -5., Ymin = -5., Zmin = 0.;

    Analiza(cos, a, b, step, &Xmin, &Ymin, &Zmin);

    cout << "Wyniki Analizy (metoda referencji): " << endl
         << "Minimalna wartosc funkcji: " << Zmin << endl
         << "Jej wspolrzedne (X, Y) = ("   << Xmin << " , " << Ymin << " )" << endl;
}
