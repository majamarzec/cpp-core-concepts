#include <iostream>
#include <cmath>
using namespace std;

int SumDigits (int n){

    int sumaResult = 0;
    if (n == 0) return sumaResult;
    else return (n % 10) + SumDigits(n / 10);
}

int NWDrec (int a, int b){

    float reszta = fmod(max(a, b), min(a, b));
    if (reszta == 0) return min(a, b);
    else return NWDrec(min(a, b), reszta);
}

int ExpRec(double x, int Nstep, int Nmax){

    if (Nstep > Nmax) return 1;
    else  return 1 + (x / Nstep) * ExpRec(x, Nstep + 1, Nmax);
}

int FiboRec(int N){
    if (N == 0) return 0;
    if (N == 1) return 1;
    else return FiboRec(N-1) + FiboRec(N-2) ;
}

// jeszcze 2 do napisania

int main(){
    cout << SumDigits(1234) << endl;
    cout << NWDrec(50, 100) << endl;
    cout << FiboRec(10) << endl;
}