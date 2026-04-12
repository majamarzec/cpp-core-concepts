#include <iostream>
#include <cstring>

using namespace std;

void Wypisz (char* Imiona[], size_t size) {
    for (int i = 0; i < size; i++){
        cout << Imiona[i] << ' ' << flush; // flush - z bufora laduje na ekranie
    }
    cout << endl;
}

// omowienie buuble_sort na postawie schematu ze strony
// kolejne skanowanie
// jedno skanowanie gwarantuje ze najwiekszy element znajdzie sie na koncu
// czyli stopniowo zawezamy liczbe czytan (do maks n-1 skanowan)
// bardzo nieefektywne ale poczatkowe do skomplikowanych np. QuickSort
// zlozonosc n^2/2 a sa takie ze n^2/logn


void Sortuj (char* Imiona[], size_t size) {

    for (int reading = 1; reading <= size - 1 ; reading++){
        for (int col = 0; col <= size - (1 + reading) ; col++){
            if ( strlen( Imiona[col] ) > strlen ( Imiona[col + 1] )){
                swap(Imiona[col], Imiona[col+1]); // dokladnie zamienia adresy zerowych elementow tych cstringow
            }
        }
    }
}


int main () {
  char imie1[] = "Staszek", imie2[] = "Konstanty" , 
       imie3[] = "Ania"   , imie4[] = "Jagoda"    ,
       imie5[] = "Rafal"  , imie6[] = "Ewa"       ;

  // kazde z imion oznacza adresy pierszych elementow poczatkow 
  // tablica imiona to szescioelementowa tablica statyczna ktorej kazdy z elementow jest wskaznikiem na char
  char* imiona[] = { imie1, imie2, imie3, imie4, imie5, imie6 };

  // wyciagniecie automatyczne ile jest tych imion
  int size = sizeof(imiona) / sizeof(imiona[0]) ;
  
  Wypisz (imiona, size);
  Sortuj (imiona, size);
  Wypisz (imiona, size);

  return 0;
}