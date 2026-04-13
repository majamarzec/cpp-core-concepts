#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// prototyp
double ranGen(double a, double b);

// implementacja
double ranGen(double a, double b)
{
	return a + (b - a) * rand() / (double)RAND_MAX;
}

int main()
{
	srand(time(NULL));   // randomizacja ziarna
    const int N = 100000;

    double successCounter = 0;

    for (int i = 0; i < N; i++){
        double X = ranGen(0,1), Y = ranGen(0,M_PI);
        if (Y < (sqrt( 1 - pow(X,2) ) ) ) successCounter++;
    }
    cout << successCounter/N  << endl;
}