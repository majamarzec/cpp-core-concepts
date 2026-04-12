#include <iostream>
using namespace std;

int main () {
  int Nmax;
  cout << "Podaj Nmax od 0 do 5000: ";
  cin >> Nmax;

  // stworzenie tabeli statycznej
  bool Primary[5000];
  for (int i = 0 ; i < Nmax ; i++) 
       Primary[i] = true;
  
  // sito Erastotenesa
  for (int scan = 2; scan < Nmax; scan++) {
    if (Primary[scan] == true) {
      for (int z = scan*2 ; z < Nmax ; z += scan) // wykreslamy wszytskie wielokrotnosci
           Primary[z] = false;
    }
  }

  // wypisanie na ekran tego co zostalo
  for (int liczba = 2; liczba < Nmax; liczba++)
    if (Primary[liczba] == true) 
      cout << liczba << ' ' << flush; 
}
