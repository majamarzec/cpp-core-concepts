#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double ranGen(double a, double b) {
    return a + (b - a) * rand() / (double)RAND_MAX;
}

int main() {
    srand(time(NULL));
    const int N = 10000000; // Zadanie prosi o 10^7 losowań

    int pointsInCircle = 0;
    int pointsUnderParaboloid = 0;

    for (int i = 0; i < N; i++) {
        // Losujemy X i Y w kwadracie obejmującym koło
        double X = ranGen(-1, 1);
        double Y = ranGen(-1, 1);

        // Sprawdzamy, czy punkt [X, Y] mieści się w kole o promieniu 1
        if (X * X + Y * Y <= 1.0) {
            pointsInCircle++; // Zliczamy losowania, które trafiły w koło

            // Losujemy wysokość Z
            double Z = ranGen(0, 1);

            // Sprawdzamy, czy punkt leży pod paraboloidą
            if (Z <= X * X + Y * Y) {
                pointsUnderParaboloid++;
            }
        }
    }

    // Objętość walca (ograniczającego naszą bryłę) wynosi Pi
    double cylinderVolume = M_PI;

    // Przybliżona objętość to proporcja trafień pomnożona przez objętość walca
    double expectedVolume = cylinderVolume * ((double)pointsUnderParaboloid / pointsInCircle);

    cout << "Wynik z symulacji: " << expectedVolume << endl;
    cout << "Oczekiwane Pi / 2: " << M_PI / 2.0 << endl;

    return 0;
}