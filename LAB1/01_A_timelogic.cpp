#include <iostream>
using namespace std;

int main () {
    int rok = 2028;

    if (rok == 2025) {
        cout << "You're in the present." << endl;
    } else if (rok < 2025) {
        cout << "Welcome to the past." << endl;
    } else {
        cout << "You're in the future." <<endl;
    }

}