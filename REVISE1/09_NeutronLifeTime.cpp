#include <iostream>
#include <cmath>

using namespace std;


void NeutronLifeTime(double T_tab[], double delta_T_tab[], size_t tab_size, double& srednia, double& niepewnosc){

    double licznik = 0., mianownik = 0.;

    for (int i = 0; i < tab_size; i++){

        licznik += T_tab[i]/ pow(delta_T_tab[i], 2);
        mianownik += 1/ pow(delta_T_tab[i], 2);
    }

    srednia = licznik / mianownik;
    niepewnosc = sqrt(1/mianownik);

}


int main() {


    double T_tab[8] = {877.75, 878.3, 877.7, 881.5, 880.2, 882.5, 880.7, 878.5};
    double delta_T_tab[8] = {0.28, 1.6, 0.7, 0.7, 1.2, 1.4, 1.3, 0.5};

    size_t tab_size = sizeof(T_tab) / sizeof(T_tab[0]);

    double srednia = 0., niepewnosc = 0.;

    NeutronLifeTime(T_tab, delta_T_tab, tab_size, srednia, niepewnosc);

    cout << "Srednia: " << srednia << endl
         << "Niepewnosc: " << niepewnosc << endl;

}