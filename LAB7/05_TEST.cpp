#include <iostream>
using namespace std;

int Silnia (int N) {
  if ( N == 0 || N == 1 ) return N;
  return N * Silnia( N - 1 );
}

void Wypelnij (int tab[], int rozmiar_tab) {
    for (int i = 0; i < rozmiar_tab; i++){
        tab[i] = Silnia(i); // flush - z bufora laduje na ekranie
    }
    cout << endl;
}

void Wypisz (int tab[], int rozmiar_tab) {
    for (int i = 0; i < rozmiar_tab; i++){
        cout << tab[i] << ' ' << flush; // flush - z bufora laduje na ekranie
    }
    cout << endl;
}

int main () {
  int tab[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int rozmiar_tab = sizeof(tab)/ sizeof(tab[0]);

  Wypelnij (tab , rozmiar_tab) ;
  Wypisz   (tab , rozmiar_tab) ;
  return 0;
}

// supi, wyszło i pytania tez g