#include <iostream>
#include <cmath>
using namespace std;

int main (int argc, char* argv[]){
    
    // monity bledow (na tablice/ do pliku - logs)!
    if ( argc != 4 ) {
        cerr << "* Usage: ./a.out value operation value\n";
        exit (1); // jesli blad to zwykle nie zero; dzialanie w przestrzeni ludzkiej
        // na twardo wyjscie return -> exit; zwlaszcza dla funkcji pomocnicznych wtedy wymuszamy wylaczenie programu
    }

    // nawiasy kwadratowe bardzo pomagaja
    char c = * (argv[2]); // lub argv[2][0], argv[2] prowadzi nas do adresu ctringa a pozniej [0] moze nas przeniesc do wskazanego elementu cstringa (elementu de facto a nie jego adresu)
    float a = atof(argv[1]), b = atof(argv[3]), wynik;

  
    switch (c) {
        case '+' : wynik = a + b;        break;
        case '-' : wynik = a - b;        break;
        case '*' : wynik = a * b;        break; // nie nalezy robic w wywolaniu po prostu gwiazdki!!// dla linuxa * to zestaw wszystkich plikow w danej sciezce ! // trzeba to oprotegowac bo inaczej ammy znak kontrolny
        case '/' : if (b == 0) {
                    cout << "Proba dzielenia przez zero.\n";
                    return -1;
                }
                wynik = a / b;        break;
        case 'f' : wynik = fmod  (a, b); break; // reszta z dzielenia
        case 'p' : wynik = pow   (a, b); break;
        case 'h' : wynik = hypot (a, b); break; // pierwiastek z a^2 + b^2
        default  : cout << "Niestety, symbol nieprzewidziany.\n";
                return -1;
  }

  cout << "Wynik dzialania to: " << wynik << endl;

  return 0;
}

// oprotegowanie mnozenia \* !!