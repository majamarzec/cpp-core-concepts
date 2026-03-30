#include <iostream>
#include <cmath>
using namespace std;


int main () {
    int a, b, c;
    cout << "Enter three non-negative intiger numbers: ";
    cin >> a >> b >> c;

    int upLimit_temp = max(a,b);
    int upLimit = max(upLimit_temp,c);

    for (int i = upLimit ; i > 0; i--){
        if (i - a > 0){
            cout << ' ';
        } else cout << '*';

        if (i - b > 0) {
            cout << ' ';
        } else cout << '*';

        if (i - c > 0){
            cout << ' ' << endl;
        } else cout << '*' << endl;
        
    }
}
