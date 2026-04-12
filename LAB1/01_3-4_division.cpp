#include <iostream>
using namespace std; 

int main () {
  int a , b ;

  cout << "Podaj dwie liczby: " << endl;
  cin >> a >> b;

  if (b == 0) {
    cout << "Nie dziel przez zero!" << endl;
    return 0;
  }
    
  else {
    float c =(float) a/b;
    cout << "Wynik dzielenia: " << c << endl;
   }

  return 0; 
}
