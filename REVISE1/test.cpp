#include <iostream>
#include <cmath>
#include <typeinfo>

using namespace std;


auto myFun (int X){
    return X = 0.5;
}
int main(){
    int k = 2, m = 3;
    int p = (++k) * (m++);
    cout << p << " " << m << endl;

    auto X = 5/3 + (double) 3;
    auto Y = myFun(int(X));

    cout << "Typ X: " << typeid(X).name() << endl
         << "Typ Y: " << typeid(Y).name() << endl;

}