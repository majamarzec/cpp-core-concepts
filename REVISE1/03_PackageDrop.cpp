#include <iostream>
#include <cmath>
using namespace std;

// Parametry globalne symulacji
const double dt = 0.01; // Krok czasowy (delta t) - 1/100 sekundy

double NoAirSimulation(double H, double g = 9.81) {
    double h_real = H;
    double t = 0;
    double v = 0; // Aktualna prędkość chwilowa

    while (h_real > 0) {
        v += g * dt;        // Przyspieszenie ziemskie zwiększa prędkość
        h_real -= v * dt;   // Prędkość zmniejsza wysokość
        t += dt;            // Czas płynie o krok dt
    }

    return H / t; // Zwracamy prędkość średnią
}

double AirSimulation(double H, int m, double g = 9.81) {
    // constVal zawiera w sobie: 0.5 * wsp. oporu (C_x) * gęstość pow. * pole przekroju / masę
    double constVal = 0.5 * 0.7 * 1.21 * 0.5 / m; 
    
    double h_real = H;
    double t = 0;
    double v = 0; // Aktualna prędkość chwilowa
    
    while (h_real > 0) {
        // Przyspieszenie to g minus opóźnienie od powietrza (zależne od v kwadrat)
        double a = g - (constVal * v * v);      
        
        v += a * dt;        // Nowa prędkość
        h_real -= v * dt;   // Nowa wysokość
        t += dt;            // Płynie czas
    }

    return H / t;
}

int main() {
    double H0 = 1200; // m - wysokosc poczatkowa
    int m = 10;       // kg - masa paczki
    double g = 9.81;  // m/s^2 - przyspieszenie

    double V_ideal = NoAirSimulation(H0, g);
    double V_air = AirSimulation(H0, m, g);

    cout << "Srednia predkosc bez oporu powietrza: " << V_ideal << " m/s" << endl;
    cout << "Srednia predkosc z oporem powietrza: " << V_air << " m/s" << endl;

    return 0;
}