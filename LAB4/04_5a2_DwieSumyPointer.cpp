//crazy drugi sposob
// bardziej ciekawostka
 
#include <iostream>
using namespace std;

void DwieSumy (int a, int b, int* &PtrSumaPar, int** Ptr2_SumaNPar) {
  for (int i = a; i <= b; i++) {
    if (i%2 == 0) *PtrSumaPar  += i;
    else          * ( *Ptr2_SumaNPar ) += i;
  }
}

int main () {
  int A, B;
  cout << "Podaj zakres [A, B] " ;
  cin >> A >> B;
  int SumaPar = 0, SumaNPar = 0;
  int* PtrSumaPar = &SumaPar , * PtrSumaNPar = &SumaNPar ;
  DwieSumy (A, B, PtrSumaPar, &PtrSumaNPar) ;
  cout << "Suma liczb    parzystych = " << SumaPar << endl;
  cout << "Suma liczb nieparzystych = " << SumaNPar << endl;
}

