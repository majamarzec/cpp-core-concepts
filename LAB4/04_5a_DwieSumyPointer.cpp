#include <iostream>
using namespace std;

// wskaznik to zmienna do przechowywania ADRESU w pamięci zmiennej danego typu
// pointer daje mozliwosc komunikacji miedzy funkcjami przez argumenty wejscia

//wiec trzeba je wyluskac 
void DwieSumy (int a, int b, int* SumaPar, int* SumaNPar) {
  for (int i = a; i <= b; i++) {
    if (i%2 == 0) *SumaPar  += i; // operator wyłuskania (dereference) adres zmiennej --> zmienna
    else          *SumaNPar += i;
  }
}



void ord3(double* a, double* b, double* c){
    
    if (*a > *b) {swap(*a, *b);}
    if (*a > *c) {swap(*a, *c);}
    if (*b > *c) {swap(*b, *c);}
}

int main(){
    cout << "Podaj dwie liczby całkowite a i b stanowiące końce przedziału [a,b]: " << endl;
    int a,b;
    cin >> a >> b;
    int SumaPar = 0, SumaNpar = 0;
    DwieSumy(a, b, &SumaPar, &SumaNpar);
    cout << "Suma liczb    parzystych = " << SumaPar << endl;
    cout << "Suma liczb nieparzystych = " << SumaNpar << endl;

    cout << "Podaj 3 liczby a, b i c: " << endl;
    double A, B, C;
    cin >> A >> B >> C;
    ord3(&A, &B, &C);

    cout << "Twoje liczby ustawione w kolejności rosnącej: " 
         << A << ' ' << B << ' ' << C << endl;
    return 0;
}