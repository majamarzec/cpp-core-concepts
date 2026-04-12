#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// generacja liczb pseudolosowych + switch case + funkcje przeciązone

double ranGenD(double a, double b)
{
	return a + (b - a) * rand() / (double)RAND_MAX;
}

int ranGenI(int a, int b)
{
	return a + rand() % (b - a);
}

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

    switch(x){
      case (1) : 
        idx = ranGenI(400000, 500000);
        PrintData(idx);
        break;
      
      case (2) :
        idx = ranGenI(400000, 500000);
        sredniaOcen = ranGenD(2,5);
        PrintData(idx, sredniaOcen);
        break;
    }

}