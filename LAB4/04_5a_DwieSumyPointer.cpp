#include <iostream>
using namespace std;

// wskaznik to zmienna do przechowywania ADRESU w pamięci zmiennej danego typu
// pointer daje mozliwosc komunikacji miedzy funkcjami przez argumenty wejscia

void DwieSumy (int a, int b, int* SumaPar, int* SumaNPar) {
  for (int i = a; i <= b; i++) {
    if (i%2 == 0) *SumaPar  += i; // operator wyłuskania (dereference) adres zmiennej --> zmienna
    else          *SumaNPar += i;
  }
}

int main () {
  int A, B;
  cout << "Podaj zakres [A, B] " ;
  cin >> A >> B;
  int SumaPar = 0, SumaNPar = 0;
  DwieSumy (A, B, &SumaPar, &SumaNPar) ;
  cout << "Suma liczb    parzystych = " << SumaPar << endl;
  cout << "Suma liczb nieparzystych = " << SumaNPar << endl;
}
