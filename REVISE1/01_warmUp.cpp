#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double a, b, c;

    cout << "Podaj trzy liczby zmiennoprzecinkowe oddzielone spacją: " << endl;
    cin >> a >> b >> c;

    double MaxVal = max(a, max(b , c));
    double MinVal = min(a, min(b , c));

    cout << "Max: " << MaxVal << endl
         << "Min: " << MinVal << endl;
}