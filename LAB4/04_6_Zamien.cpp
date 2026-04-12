#include <iostream>
using namespace std;

void Zamien (char& c){

    int changeBias = 'a' - 'A';

    if ( (c < 'A') || ((c > 'Z') && (c < 'a')) || (c > 'z') )
        cout << "Niepoprawny znak graficzny!" << endl;

    else if ((c >= 'A') && ( c <= 'Z')){
        cout << "Zamieniam znak z litery wielkiej na mala" << endl;
        c += changeBias;
    }
    
    else {
        cout << "Zamieniam znak z litery malej na wielka" << endl;
        c -= changeBias;
    }

}

// funkcja przeciazona

void Zamien (char* c){

    int changeBias = 'a' - 'A';

    if ( (*c < 'A') || ((*c  > 'Z') && (*c  < 'a')) || (*c  > 'z') )
        cout << "Niepoprawny znak graficzny!" << endl;

    else if ((*c  >= 'A') && ( *c  <= 'Z')){
        cout << "Zamieniam znak z litery wielkiej na mala" << endl;
        *c  += changeBias;
    }
    
    else {
        cout << "Zamieniam znak z litery malej na wielka" << endl;
        *c  -= changeBias;
    }

}



int main() {

    char C;
    cout << "Podaj znak graficzny (mala lub wielka litere): " << endl;
    cin >> C;

    char C2 = C; //kopia

    Zamien(C);
    Zamien (&C2);

    cout << "Twoj znak po zamianie (wskazniki): " << C2 << endl;

}