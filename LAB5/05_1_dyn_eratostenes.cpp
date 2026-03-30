#include <iostream>
using namespace std;

int main () {
  int Nmax;
  cout << "Podaj Nmax od 0 do 5000: ";
  cin >> Nmax;
  //bool Primary[5000];

  bool* Primary = new bool [Nmax]; // dynamiczna alokacja

  for (int i = 0 ; i < Nmax ; i++) 
       Primary[i] = true;
  
  for (int scan = 2; scan < Nmax; scan++) {
    if (Primary[scan] == true) {
      for (int z = scan*2 ; z < Nmax ; z += scan) 
           Primary[z] = false;
    }
  }

  for (int liczba = 2; liczba < Nmax; liczba++)
    if (Primary[liczba] == true) 
      cout << liczba << ' ' << flush; 

  delete[] Primary; //tu jest koniec kody w ogole, wiec komputer sam zwija pamiec = odblokowuje alokacje
}
