//zadanie 1 seria 2

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main(){

    // w nazwie zmiennych nie oszczędzaj liczby liter
    // niech nazwa będzie czytelna w konktekście 

    int value; //zawsze wczytywana przez uzytkownika, nie trzeba inicjalizowac 
    int maxval = INT_MIN, minval = INT_MAX; // stałe z climits, rozne dla roznych PC
    int NmaxTimes = 0, NminTimes = 0;

    cout << "Podaj ciąg liczb calkowitych oddzielonych spacjami: ";

    while (true){ // lub 1

        cin >> value;

        if (value == 0) break; // nie trzeba opakować nawiasami bo tylko jedno plecenie

        if (value == maxval) {
            NmaxTimes++; //inkrementacja
        }

        if (value > maxval) {
            maxval = value;
            NmaxTimes = 1;
        }

        if (value == minval){
            NminTimes++;
        }

        if (value < minval){
            minval = value;
            NminTimes = 1;
        }}

    // wypisanie po przejsciu przez wszystkie elementy    
    cout << "Min: " << minval << ',' << " NminTimes " << NminTimes << endl;
    cout << "Max: " << maxval << ',' << " NmaxTimes " << NmaxTimes << endl;

    return 0;
}

