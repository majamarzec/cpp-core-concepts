#include <iostream>
#include <cmath>

using namespace std;


void AnalizujCzasyZycia(double T_tab[], double delta_T_tab[], size_t tab_size, 
                        double& srednia, double& niepewnosc){

    double licznik = 0., mianownik = 0.;

    for (int i = 0; i < tab_size; i++){

        licznik += T_tab[i]/ pow(delta_T_tab[i], 2);
        mianownik += 1/ pow(delta_T_tab[i], 2);
    }

    srednia = licznik / mianownik;
    niepewnosc = sqrt(1. / mianownik);

}


int main() {


    double T_tab[6] = {877.75, 878.3, 877.7, 881.5, 880.2, 882.5};
    double delta_T_tab[6] = {0.34, 1.9, 0.76, 0.81, 1.2, 2.1};

    size_t tab_size = sizeof(T_tab) / sizeof(T_tab[0]); // obie tablice maja te same rozmiary

    double T_sred, dT_sred;

    AnalizujCzasyZycia(T_tab, delta_T_tab, tab_size, T_sred, dT_sred);

    cout << "Srednia czasu zycia neutronu: " << T_sred << " s" << endl
         << "Niepewnosc tego pomiaru: " << dT_sred  << " s" << endl;

}