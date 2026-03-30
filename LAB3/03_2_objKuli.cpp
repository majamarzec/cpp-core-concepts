#include <iostream>
#include <cmath>
using namespace std;

// prototypy
double ObjKuli(double R);
double ObjKuli(double R, int N);
int Silnia(int n);
int Dwusilnia(int n);

// [wariant 1] objętość kuli w 3D
double ObjKuli(double R)
{
	return 4.0 / 3.0 * M_PI * R * R * R;
}

// [wariant 2] objętość kuli w N wymiarach
double ObjKuli(double R, int N)
{
	if (N == 1)
    	return 2.0 * R;

	if (N % 2 == 0) // N = 2k
	{
    	int k = N / 2;
    	return pow(M_PI, k) / Silnia(k) * pow(R, N);
	}
	else // N = 2k - 1
	{
    	int k = (N + 1) / 2;
    	return pow(2.0, k) * pow(M_PI, k - 1) / Dwusilnia(N) * pow(R, N);
	}
}

// funkcja rekurencyjna - silnia
int Silnia(int n)
{
	if (n == 0 || n == 1)
    	return 1;
	return n * Silnia(n - 1);
}

// funkcja rekurencyjna - dwusilnia
int Dwusilnia(int n)
{
	if (n == 0 || n == 1)
    	return 1;
	return n * Dwusilnia(n - 2);
}

int main()
{
	double R;
	int N;

	cout << "Podaj promien R: ";
	cin >> R;

	cout << "Podaj wymiar N: ";
	cin >> N;

	double V;

	switch(N){ 
    	case 3:
        	V = ObjKuli(R);   	// wersja 3D
        	break;
    	default:
        	V = ObjKuli(R, N);	// wersja N-wymiarowa
    }

	cout << "Objetosc = " << V << endl;

	return 0;
}