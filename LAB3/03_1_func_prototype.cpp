#include <iostream>
#include <cmath>
using namespace std;

// Prototypy funkcji
double Length (double, double);
double DotProduct (double, double, double, double);
double Angle (double, double, double, double);


int main() {
	float v1x = 2., v1y = 0.;
	float v2x = 0., v2y = 2.;
	float v2v1x = -2., v2v1y = 2.;
	float v2v2x = -2., v2v2y = 0.;

	cout << "Kat (a): " << Angle(v1x, v1y, v2x, v2y) << " stopni" << endl;
	cout << "Kat (b): " << Angle(v2v1x, v2v1y, v2v2x, v2v2y) << " stopni" << endl;

	return 0;
}

// Implementacje funkcji
float Length(float x, float y) {
	return sqrt(x * x + y * y);
}

float DotProduct(float x1, float y1, float x2, float y2) {
	return x1 * x2 + y1 * y2;
}

float Angle(float x1, float y1, float x2, float y2) {
	float cos_angle = DotProduct(x1, y1, x2, y2) / (Length(x1, y1) * Length(x2, y2));
	return acos(cos_angle) * 180.0 / M_PI;
}
