#include <iostream>
#include <string>
using namespace std;



int main (int argc, char* argv[]) {

   // monity bledow (na tablice/ do pliku - logs)!
  if ( argc != 3 ) {
        cerr << "* Usage: ./a.out value operation value\n";
        exit (-1); // jesli blad to zwykle nie zero; dzialanie w przestrzeni ludzkiej
        // na twardo wyjscie return -> exit; zwlaszcza dla funkcji pomocnicznych wtedy wymuszamy wylaczenie programu
  }

  string Imie1 = (string) argv[1];
  string Imie2 = (string) argv[2];

  

  cout << "Imiona: " <<  Imie1 << ' ' <<  Imie2 << endl;

  
  string s = "- Programowanie jest proste - stwierdzila Monika.\n"
              "- Serio? - zapytal Rafal.\n"
               "- Serio - odpowiedziala.\n";

  int Nzdan = 0, Nlinii = 0;
  size_t posFound = -1, indx = -1; // zeby zaczynac od pierwszego znaku


  do {
    posFound = s.find_first_of(".?", posFound + 1);
    if (posFound != string::npos){ // string::npos jest typu size_t
        Nzdan++;
    } 
  } while (posFound != string::npos);

  do {
    indx = s.find_first_of("\n", indx + 1) ;
    if (indx != string::npos)
        Nlinii++ ;
  } while ( indx != string::npos ) ;


  // gdzie ta Monika??
  // size_t to typ do wszelakich lokalizacji i pozycji (to tak na prawdę int)

  size_t posMonika = s.find("Monika"); // wiemy gdzie sie zaczyna + wiemy ze ma 6 literek
  s.replace(posMonika, 6, Imie1);

  size_t posRafal = s.find("Rafal"); // wiemy gdzie sie zaczyna + wiemy ze ma 5 literek
  s.replace(posRafal, 5, Imie2);

  cout << "Wykrytych zdan: " << Nzdan << endl;
  cout << "Wykrytych linii: " << Nlinii <<endl;
  cout << "Nowy string: " << s << endl;
  return 0;
}


// jak dziala algorytm przeszukiwaniu po stringu?

// do dokonczenia

// liczba linii konczy sie znakiem /n
// zamiana tez w petli z uzyciem s.find i s.insert i s.replace