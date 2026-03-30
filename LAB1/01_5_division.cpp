#include <iostream>
using namespace std; 

int main () {
  int a , b ;

  while (true){

    cout << "Podaj dwie liczby: ";
    cin >> a >> b;

    if (a != 0) {
        if (b == 0) {
            cout << "Nie dziel przez zero!" << endl;
        }
    
        else {
            float c =(float) a/b;
            cout << "Wynik dzielenia: " << c << endl;
        }
    }
    else {
        cout << "Obie liczby nie mogą być zerami! Nieoznaczoność!";
        break; }
}

  return 0; 
}