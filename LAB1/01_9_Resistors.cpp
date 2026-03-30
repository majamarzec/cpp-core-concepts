#include <iostream>
#include <cmath>
using namespace std;


int main() {

    double R1, R2, U, Imax;

    cout << "Podaj wartosci R1, R2, U, Imax: ";
    cin >> R1 >> R2 >> U >> Imax;

    char p;
    cout << "Jak połączono oporniki?" << endl << "Wpisz s jesli szeregowo lub r jesli rownolegle: ";
    cin >>p;

    double res = 0;
    cout << "Opor zastepczy dla R1 i R2 polaczanych ";
    if (p == 's'){
        res += R1 + R2;
        cout << "szeregowo wynosi " << res << " Om."<<endl;
    }
    else {
        res += 1/(1/R1 + 1/R2);
        cout << "rownolegle wynosi" << res << " Om."<<endl;
    }

    cout << "Wartość łącznego natężenia prądu przechodzącego przez urządzenie wynosi ";
    double Iall = U/ res;
    cout << Iall << "A.";

    if (Iall <= Imax) cout << " | natęzenie w normie" << endl;
    else cout << " | natezenie POZA NORMA" << endl;

}