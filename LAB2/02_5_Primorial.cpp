#include <iostream>
using namespace std;

bool isPrime (int n) {
// ...
}

// primorial to iloczyn wszytskich liczb pierwszych do N
int primorial (int n) {
    int iloczyn = 1;
    // wybieramy for bo petla po indeksie
    for (int idx = 1; idx <= n; idx++){
        if ( isPrime(idx) == true) {
            iloczyn *= idx;
        }
    return iloczyn;
    }
}

int main() {
    cout << " N N# \n";

    for (int n = 0; n <= 11; ++n)
    cout << n << '\t' << primorial(n) << '\n';
}