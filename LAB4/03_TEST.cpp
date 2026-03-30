#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int PrintData(int indeks){
  cout << "Indeks studenta: " << indeks << endl;
  return 0;
}

int PrintData(int indeks, double sredniaOcen){
  cout << "Indeks studenta: " << indeks << endl 
       << "Średnia ocen: " << sredniaOcen << endl;
  return 0;
}

int main () { 
    srand ( time (NULL) );
    cout << "Podaj ile danych jest upulicznionych - wpisz 1 lub 2: ";
    int x;
    int idx;
    double sredniaOcen;

    cin >> x;

    if (x == 1){
      idx = 400000. + 100000. * ( rand () / float( RAND_MAX ));
      PrintData(idx);
    }

    else{ 
      idx = 400000. + 100000. * ( rand () / float( RAND_MAX ));
      sredniaOcen = 2. + 3. * ( rand () / float( RAND_MAX )); 
      PrintData(idx, sredniaOcen);
    }

    return 0;
}