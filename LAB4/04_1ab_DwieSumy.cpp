#include <iostream> 
#include <cmath>
#include <algorithm> // odkrycie nowej biblioteczki
using namespace std;

// referencja to nowa nazwa na zmienną
// glowna uzytecznosc referencji
// przy przekazywaniu zmiennej do funkcji 
// operujemy bezposrednio na podanej do podfunkcji zmiennej a nie na jej kopii

void DwieSumy( int a, int b , int& SumaPar, int& SumaNpar){
    for (int i = a; i<=b; i++){
        if ( i%2 == 0 ){
            SumaPar += i;
        }
        else{
            SumaNpar += i;
        }
    }
    cout << "Suma liczb parzystych wynosi: " << SumaPar << "\n"
         << "Suma liczb nieparzystych wynosi: " << SumaNpar << flush;
    cout << endl;
}

void ord3(double& a, double& b, double& c){
    if (a > b) {swap(a,b);}
    if (a > c) {swap(a,c);}
    if (b > c) {swap(b,c);}
}

int main(){
    cout << "Podaj dwie liczby całkowite a i b stanowiące końce przedziału [a,b]: " << endl;
    int a,b;
    cin >> a >> b;
    int SumaPar = 0, SumaNpar = 0;
    DwieSumy(a, b, SumaPar, SumaNpar);

    cout << "Podaj 3 liczby a, b i c: " << endl;
    double A, B, C;
    cin >> A >> B >> C;
    ord3(A, B, C);

    cout << "Twoje liczby ustawione w kolejności rosnącej: " 
         << A << ' ' << B << ' ' << C << endl;
    return 0;
}

