#include <iostream>
using namespace std;

long long silnia (int N){

    if ((N == 0) || (N == 1))
        return 1;
    else
        return N * silnia( N - 1); //wywołanie rekurencyjne
}

int main(){

    int N;
    while(true){
        cout << "Podaj liczbe calkowita N: " << endl;
        cin >> N;
        if (N >= 0)
            cout << "N! = " << silnia(N) << endl;
        else
            cout << "Liczba musi byc nieujemna!" <<endl;
    }
}