#include <iostream>
#include <cmath>
using namespace std;

double silnia (double x){

    if ((x == 0) || (x == 1))
        return 1;
    else
        return x * silnia( x - 1);
}


void Wypisz (double tab[], int rozmiar_tab) {
    for (int i = 0; i < rozmiar_tab; i++){
        cout << i << " element : " << tab[i] << ' ' << endl; 
    }
    cout << endl;
}


double MyExp (double x, int N, double epsilon){

    double tab[N];
    double funValue = 0.;
    for (int i = 0; i <= N; i++){
        double temp = pow(x, i) / silnia(i);
        funValue += temp;
        if (temp > epsilon) tab[i] = temp;
        else {
            cout << "Przekroczono epsilon: " << epsilon << 
                    "W kroku: " << i <<
                    ". Wyliczona do tego kroku suma: " << funValue << endl;
            exit (-1);
        }
    }

    cout << N << " pierwszych wyrazow szeregu Taylora dla x= " << x << " to: " <<endl;

    Wypisz(tab, N);

    return funValue;
}


int main() {

    double x, eps;
    int n;

    cout << "Podaj x (liczba zmiennoprzecinkowa),  n (liczba całkowita) oraz epsilon (liczba zmiennoprzecinkowa - rzedu np. 1e-06): " << endl;
    cin >> x >> n >> eps;

    MyExp(x, n, eps);

}