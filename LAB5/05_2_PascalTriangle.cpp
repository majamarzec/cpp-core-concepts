#include <iostream>
#include <iomanip>
using namespace std;

// dwuwymiarowe tablice statyczne!


int main () {
  int tab[12][12] ;  // [rows (r)][columns (k)]
  for (int r = 0; r < 12; r++) {
    tab[r][0] = 1;
    tab[r][r] = 1;
	
    for (int k = 1; k<r; k++){
        tab[r][k] = tab[r-1][k-1] + tab[r-1][k];
    }
  }
  for (int r = 0 ; r <12; r++){
    for (int k = 0; k <= r ; k++){
        cout << setw (4) << right << tab[r][k] << ' ' <<flush; // right - adjustuj do prawej, setw (4) - ustaw liczbe znakow gwarantowanych na element
    }
    cout << endl; // jak konczymy z rzedem to idziemy do nowej linii
  }
}
