#include <iostream>
#include <cmath>
using namespace std;

void Losuj(double& v0, double& kat){
    v0 = 110 + rand() % (130-110); //losowanie z przedziału [110,130]
    v0 = v0*1000/3600.; //zamiana na m/s
    kat = 28 + rand() % (32-28); //losowanie z przedziału [28,32]
    kat = kat*2*M_PI/360; //zamiana kata na radiany
}

int main(int argc, char* argv[])
{   
    srand(time(NULL)); 
    int Nlosowan = atoi(argv[1]);
    double v0 = 0., kat = 0., Z = 0.;
    double g = 9.81;
    double srednia = 0, dyspersja = 0;
    
    for(int i = 1; i <= Nlosowan; i++){

        Losuj(v0, kat);

        Z = 2 * v0 * sin(kat) *cos(kat) / g; //zasieg

        srednia += Z;
        dyspersja += Z * Z;
    }

    srednia = srednia/ Nlosowan;
    dyspersja = sqrt((dyspersja - Nlosowan*srednia*srednia)/(Nlosowan-1));
    
    cout << "Sredni zasieg: " << srednia << endl;
    cout << "Dyspersja: " << dyspersja << endl;
     
}