#include <iostream>
using namespace std;


// ma zwracac status (roznicujemy 2 sytuacje) -> feedback
// taśmociąg
int Zarzadzanie(int* pamiec){
    cout << "Podaj rozmiar tablicy: ";
    size_t N;
    cin >> N;
    if (N <=0) return -1; // mozna skipnac nawiasy bo jedno polecenie

    int* tab = new int[N]; // dynamiczna alokacja pamieci dla tablicy tab
    for (int pos = 0; pos < N; pos++){
        cout << " Podaj tab[" << pos << "] : ";
        cin >> tab[pos];
        }

    for (int pos = 0; pos < N; pos++){
        cout << " Wypisuję tab[" << pos << "] = " << tab[pos] << endl;
        }


    delete[] tab; // [] zeby to byl menager do zamykania tablic
    // to jest najwazniejsze w petli (zapobieganie wyciekom pamięci) 
    return 0;
}

// dopiero main decyduje ze ma wyjsc
// moznaby zrobic exit(1), ale jest to podejscie mocno niskopozniomowe
 
int main(){

    int* pamiec;

    while (true) {
        if (Zarzadzanie(pamiec) != 0) break;
    }

    return 0;
}