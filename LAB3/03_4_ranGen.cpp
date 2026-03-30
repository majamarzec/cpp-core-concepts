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

	const int N = 1000000;
	double mean = 0.0;
	double stdev = 0.0;

	for (int i = 0; i < N; i++)
	{
    	double val = ranGen(2.0, 7.0);
    	mean += val;
    	stdev += val * val;
	}

	mean = mean / N;
	stdev = sqrt((stdev - N * mean * mean) / (N - 1));

	cout << "Srednia = " << mean << endl;
	cout << "Odch standardowe = " << stdev << endl;

	return 0;
}