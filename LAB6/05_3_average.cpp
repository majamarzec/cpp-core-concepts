#include <iostream>
#include <cmath>

using namespace std;

// czym jest to size_t? -> niemal zawsze int. to typ wymyslony po to zeby programista uzywal w kontekstach dot rozmairow
// poprzedzajac typ zmiennej const obiecujemy ze w dalszej czesci kodu nie zmienimy wartosci danego argumenty
// "sami sobie wiazemy rece", "chcemy byc sterylni"
// zwracamy wzkaźnik (adres) na zmienną const double (regula prawo-lewo)
// to nie jest const wskaznik - pudelko mozemy zmeniac
// ale nie mozemy zmieniac obiektow tego pudelka, czyli const double
// mozna stworzyc tez staly wskaznik ale to nie jest tu
// w procedurze bedziemy iterowac po adresach
// arr samo w sobie to adres pierszego elementu tablicy (trzeba sie do tego przyzwyczaic)
// mozna tez jawnie wziac pierwszy element arr[0] i wziac tego adres &arr[0]

const double* aver (const double* arr, size_t size, double& average) {

    // srednia
    for (int i = 0; i < size ; i++ ){
        average += arr[i];
    }
    average /= size;

    const double* nearest = arr ; // lub inaczej = &arr[0]
    // pocwiczmy petle po adresach
    // indeksem bedzie adres i przesuwamy sie o kolejne cegielki

    // jedziemy po adreach, ale w gruncie rzeczy lecimy tu po kolejnych elementach pętli
    for (const double* ptr = &arr[0]; ptr - arr < size; ptr++){
        if (fabs(*ptr - average) < fabs(*nearest - average)){
            nearest = ptr;
        }
    }

    return nearest; //adres elementu tablicy ktorego wartosc jest najblizsza sredniej
}

// fajne ale takie na myslenie [wskaźniki vs tablice statyczne]

int main () 
{
    double arr[] = { 1, 7, 5, 4, 3, 2 };
    size_t size = sizeof(arr) / sizeof(arr[0]); // metoda w tablicach staytycznych na wyciągnięcie rozmraiu tablicy
    double average = 0; // dzialamy na referencji tej zmiennej w aver wiec jej nie trzeba zwracac bo zmienia sie oryginal

    // jak przeniesc tablice do funkcji
    // arr - adres poczatkowego elementu tablicy !!
    // mozna tez arr[] ale to bedzie to samo co arr, bo C++ nie wie jaki jest rozmiar tablicy ("przedpotopowy pomysl z tymi tablicami")
    // mozna jako osobny "kanal" przeslac rozmiar tablicy (tutaj size)

    const double* p = aver (arr, size, average);

    cout << *p << " " << average << endl;

    return 0;
}

