#include <iostream>
#include <cmath>
using namespace std;

// koniecznie trzeba zalaczyc cmath dla funkcji tryg. i potegowania


double func (double x) {
    return 2 * tanh(x);
}

double Deriv(double x){
    return 2 * sin( 2 * x) + sin( 4 * x);
}

double AproxfPrim(double x){
    return 2/ pow(cosh(x), 2);
}


int NFoundDerivs(double P, double K, double step){

    int N_points = 0.;
    double delta_derivs = 0.;
    double delta_derivs_new = 0.;

    for (double i = P; i <= K; i += step){

        double fVal = func(i); // wartosc funkcji w punkcie
        double fPrimVal = (func(i) - func(i -step))/step; // iloraz roznicowy

        // delta_derivs_new = AproxfPrim(i) - Deriv(i); // sprawdzenie dla funkcji analitycznej
        delta_derivs_new = fPrimVal - Deriv(i);
        // jesli znak sie zmieni to oznacza przeciecie
        if (delta_derivs_new * delta_derivs < 0 ){
            N_points++;
            cout << " -> X" << N_points << " : " << i << " ";
        }
        // "nowa" roznica staje sie "stara" roznica
        delta_derivs = delta_derivs_new;
    }
    cout << endl;
    return N_points;
}


int main(){

    double P = 0, K = 4, step = 10e-3;
    int N_total;

    cout << "Wspolrzedne x-owe dla ktorych wystepuje przeciecie: ";
    N_total = NFoundDerivs(P, K, step);
    cout << "Znaleziona liczba punktow przeciecia: " << N_total << endl;
    
}