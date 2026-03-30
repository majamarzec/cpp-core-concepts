#include <iostream>
#include <cmath>
using namespace std;


int QuadraticEqSolver(double a, double b, double c){

    if (a == 0){
        cout << "Rownanie liniowe: "<< (-1 * c) / b << endl;
    }

    else{
        double delta = pow(b,2) - (4 * a * c);

        if (delta < 0){
            cout << "Rownanie nie ma rozwiązań"<< endl;
        }

        else if (delta == 0){
            cout << "Rownanie ma jedno rozwiazanie: " << (-1 * b) / (2 * a) << endl;
        }

        else {
            double res1 = (-1 * b) / (2 * a) + sqrt(delta);
            double res2 = (-1 * b) / (2 * a) - sqrt(delta);
            cout << "Rownanie ma dwa rozwiazania: "
                << res1 << " oraz " << res2 << endl;

        }
    }
    return 0;
}


int main() {

    double a, b, c;
    cout << "Podaj wspolczynniki a, b i c rownania kwadratowego: ";
    cin >> a >> b >> c;


    QuadraticEqSolver(a, b, c);

}