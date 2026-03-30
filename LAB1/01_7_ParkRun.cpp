//zadanie 7 seria 1

#include <iostream>
#include <cmath>
using namespace std;

// ćwiczymy loop for
// primitywne rozpoczęcie wątku symulacji

int main () {

    float dt = 10.; // s
    float t = 0.;
    float vB = 12.; // km/h!
    float vC = 4.; // km/h!

    //konwersja do m/s
    vB /= 3.6;
    vC /= 3.6;

    //droga
    float sB = 0.;
    float sC = 0.;
    float s_total = 5000.;
    float s_loop = s_total/3.;

    //polozenie
    float xB = 0., xC = 0.; // bardziej kompaktowy zapis

    // liczba okrazen
    int nOkrB = 0.,  nOkrC = 0.;




    /*
    Tutaj jest kwestia przeyślenia, ktora petle wybieramy (tu do .. while)

    Wcięcia się liczą!! Na kolokwium będą za to punkciki. Kod ma być czytelny.

    */

    do {
        t+=dt;
        sB += vB * dt;
        sC += vC * dt;

        xB = fmod(sB, s_loop);
        xC = fmod(sC, s_loop);

        nOkrB = sB / s_loop; //ok no nOknrB jest intem
        nOkrC = sC / s_loop;

        cout << "CZAS: " << t << '\t'
             << "sB: " << sB << '\t' 
             << "sC: " << sC << '\t' 
             << "nOkrB: " << nOkrB << '\t'
             << "nOkrC: " << nOkrC << '\t'
             << endl;

    } while  (!((xB >= xC) && (nOkrB > nOkrC)));

    return 0;
}