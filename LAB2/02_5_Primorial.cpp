#include <iostream>
#include <cmath>
using namespace std;

bool isPrime (int n) {

    if ( (n == 0) || (n == 1)) return false;

    else {
        for (int i = 2; i < n; i++){
            if (n % i == 0) return false;
        }
    }
    return true;
}

// primorial to iloczyn wszytskich liczb pierwszych do N
int primorial (int n) {
    int iloczyn = 1;
    for (int idx = 0; idx <= n; idx++){
        if ( isPrime(idx)) {
            iloczyn *= idx;
        }
    }
    return iloczyn;
}

int main() {
    cout << " N N# \n";

    for (int n = 0; n <= 11; ++n)
    cout << n << '\t' << primorial(n) << '\n';
}