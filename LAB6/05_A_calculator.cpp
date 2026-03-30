#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
  cout << "Wybierz symbol odpowiadajacy dzialaniu: [+-*/fph] ";

  char c;
  cin >> c;
  
  float a, b, wynik;
  cout << "Podaj dwa argumenty: ";
  cin >> a >> b;

  
  switch (c) {
    case '+' : wynik = a + b;        break;
    case '-' : wynik = a - b;        break;
    case '*' : wynik = a * b;        break;
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