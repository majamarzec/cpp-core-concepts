#include <iostream>
using namespace std;

int main () 

    {
    float A;
    float B;
    float H; // dzieki temu dzielenie bedzie okej a nie jak pokazywany na zajeciach problem

    cout << "Podaj 3 liczby typu float odpowiadające kolejno podstawie górnej, dolnej i wysokości trapezu.";
    cin >> A >> B >> H;

    if ((A >=0) && (B >=0) && (H >=0)){
        float pole = ((A+B)*H)/2;
        cout << "Wartość pola trapezu a podanych charakterystykach : " << pole << " [j^2]." << endl;
    }
    else {cout << "BŁAD! Wszystkie liczby powinny być nieujemne!"<< endl;}
    return 0;
}