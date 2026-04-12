#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void CalcLifeTime(double tab_wyniki[], double tab_niepewnosci[],
    int size, double& T_avg, double& dT_avg){
        
        double srednia_licznik = 0., srednia_mianownik = 0.;
        
        for (int i = 0; i < size; i++){
            srednia_licznik += tab_wyniki[i] / pow(tab_niepewnosci[i], 2);
            srednia_mianownik += 1./ pow(tab_niepewnosci[i], 2);
        }
        T_avg = srednia_licznik/srednia_mianownik;
        dT_avg = sqrt(1./srednia_mianownik);
    }


int main()
{
    double tab_wyniki[6] = {8.43, 8.337, 8.5, 8.4, 8.97, 8.2};
    double tab_niepewnosci[6] = {0.13, 0.112, 1.1, 0.5, 0.22, 0.4};
    int size = sizeof(tab_wyniki)/sizeof(tab_wyniki[0]);
    double T_avg = 0., dT_avg = 0.;
    
    CalcLifeTime(tab_wyniki,tab_niepewnosci,size,T_avg, dT_avg);
    cout <<fixed << setprecision(3)  << "T = " << T_avg << " +/- " << dT_avg << endl;
    return 0;
}