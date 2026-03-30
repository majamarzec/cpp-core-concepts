#include <iostream>
#include <cmath>
using namespace std;



 double Parabola (double x, double a, double b, double c) {

    double result = a*pow(x,2) + b*x +c;
    return result;

 }


int main() {

    double y = 0;
    double x_max = -1;
    double y_max = Parabola(-1, -1, 4, 1);

    for (double x = -1; x <=5; x+= 0.05) {

        double new_result = Parabola(x, -1, 4, 1);

        if (new_result > y_max){
            x_max = x;
            y_max = new_result;
        }
    }

    cout << x_max << y_max << endl;
    return 0;
}
