#include <iostream>
#include <cmath>

using namespace std;


double f1(double x){
    return x/5.;
}

double f2(double x){
    return 3.*sin(2.*x);
}

int Nconnect (double a, double b, double dx){

    int punkty_przeciecia = 0;
    double roznica_poprzednia = 0.;
    double roznica_aktualna = 0.;

    for (double i = a; i <= b; i+= dx){
        double x_sr = (i+ i+dx)/2.;
        roznica_aktualna = f1(x_sr) - f2(x_sr);
        if (roznica_poprzednia * roznica_aktualna < 0){//sprawdzenie czy zmienil sie znak
            punkty_przeciecia ++;
        }
        roznica_poprzednia = roznica_aktualna;
    }
    return punkty_przeciecia;
}

int main()
{
    double a = 0.01, b = 8., dx= 0.00001;
    int punkty_przeciecia =  Nconnect (a, b, dx);
    cout << "Liczba punktow przeciecia: " << punkty_przeciecia << endl;
    return 0;
}