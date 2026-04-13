#include <iostream>
#include <cmath>
#include <climits>
using namespace std;


// skorzystalam z argumentow domyslnych funkcji
// ustawiajac tym samym przedzialy losowan wartosci v0 i alphy
// tak zeby latwo dalo sie je modyfikowac

// losowanie doubli z zadanych przedzialow (wazne ze nie tylko intow)

void PodajV0alpha(double& v0, double& alpha,
                  double av0 = 30,    double bv0 = 40, 
                  double aalpha = 18, double balpha = 22) {

    double v0_km_h = av0 + (bv0 - av0) * (rand()/ double(RAND_MAX));
    v0 = v0_km_h * 1000/3600.; // konwersja km/h -> m/s

	double alpha_deg = aalpha + (balpha - aalpha) * (rand()/ double(RAND_MAX));
    alpha = alpha_deg * (2 * M_PI) / 360; // konwersja ze stopni do radianow

}

void Symulacja(int N){

    double alpha = 0., v0 = 0., TOF = 0.; // TOF = time of flight
    double g = 9.81; // m/s^2
    int N_odbic = 3;

    double srednia = 0, dyspersja = 0;
    
    for(int i = 1; i <= N; i++){

        PodajV0alpha(v0, alpha); // przekazanie za pomoca referencji

        TOF = N_odbic * (2 * v0 * sin(alpha) / g); //czas lotu wszystkich odbic

        srednia += TOF;
        dyspersja += TOF * TOF;
    }

    // wzorki z naszych LABow
    srednia = srednia/ N;
    dyspersja = sqrt((dyspersja - N*srednia*srednia)/(N-1));
    
    cout << "Sredni TOF: " << srednia << " s " << endl;
    cout << "Dyspersja: " << dyspersja << " s " << endl;

}



int main(int argc, char* argv[]){   

    // randomizacja seedu
    srand(time(NULL)); 

    // zabezpieczenie przed niepoprawnych uzyciem
    if ( argc != 2 ) {
        cerr << "* Usage: ./a.out value operation value\n";
        cerr << "* Nalezy wywolac: $ ./a.out N\n";
        cerr << "* Przy czym N ma być duza liczba calkowita np. 1000 oznaczajaca liczbe losowan\n" ;

        exit (-1); // monit o bledzie + wymuszenie wyjscia z programu
    }

    int Nlosowan = atoi(argv[1]);
    Symulacja(Nlosowan);

}