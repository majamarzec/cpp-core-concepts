#include <iostream>
#include <string>
using namespace std;



int main () {
  string s = "- Programowanie jest proste - stwierdzila Monika.\n"
              "- Serio? - zapytal Rafal.\n"
               "- Serio - odpowiedziala.\n";

  int Nzdan = 0;
  size_t posFound;


  do {
    posFound = s.find_first_of(".?", posFound + 1);
    if (posFound != string::npos){ // string::npos jest typu size_t
        Nzdan++;
    } 
  } while (posFound != string::npos);

  cout << "Wykrytych zdan: " << Nzdan <<endl;
  return 0;
}

// do dokonczenia

// liczba linii konczy sie znakiem /n
// zamiana tez w petli z uzyciem s.find i s.insert i s.replace