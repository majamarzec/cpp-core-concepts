#include <iostream> 
#include <cmath>
using namespace std;



double f (double x) {
    return atanh(x);
}
 
void Analiza (double (*fPtr) (double), double a, double b, double dx, double& MinFVal, double& MaxFVal, double& MinFPrimVal, double& MaxFPrimVal){

    for (double i = a; i <= b; i+= dx){

        double fVal = f(i), fPrimVal = (fPtr(i) - fPtr(i-dx))/dx;

        if (fVal < MinFVal) MinFVal = fVal;
        if (fVal > MaxFVal) MaxFVal = fVal;

        if (fPrimVal < MinFPrimVal) MinFPrimVal = fPrimVal;
        if (fPrimVal > MaxFPrimVal) MaxFPrimVal = fPrimVal;
    }

    cout << "Analiza zakonczona!" << endl;
}

int main(){

    double MinFVal = 0, MaxFVal = 0, MinFPrimVal = 0, MaxFPrimVal = 0;

    Analiza(cosh, 0, M_PI, 0.001, MinFVal, MaxFVal, MinFPrimVal, MaxFPrimVal);

    cout << "Wyniki Analizy (metoda referencji): " << endl
         << "Minimalna wartosc funkcji: " << MinFVal << endl
         << "Maksymalna wartosc funkcji: " << MaxFVal << endl
         << "Minimalna wartosc pochodnej: " << MinFPrimVal << endl
         << "Maksymalna wartosc pochodnej: " << MaxFPrimVal << endl;    
}