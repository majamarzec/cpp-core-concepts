# include <iostream>
# include <cmath>
# include <climits>

using namespace std;

int main(){

    int value;
    cout << "Podaj ciag liczb calkowitych (oddzielonych spacja): ";
    int SeqValue = INT_MIN;
    int SeqCounter = 0;

    while (true){

        cin >> value;

        if (value == SeqValue) SeqCounter++;
        if (value == 0) {
            cout << "Longest sequence: " << SeqValue << " ( " << SeqCounter << " times )"  << endl;
            break;
            } 

        else{
            int SeqValue2 = value;
            int SeqCounter2 = 1;
            while (true) {
                cin >> value;
                if (value == SeqValue2) SeqCounter2++;
                if (value == 0) {
                    cout << "Longest sequence: " << SeqValue << " ( " << SeqCounter << " times )"  << endl;
                    break;}
                else{
                    if (SeqCounter2 > SeqCounter){
                        SeqValue = SeqValue2;
                        SeqCounter = SeqCounter2;
                        break;
                    }
                }
            }
        }
    }
}


// do przemyslenia jeszcze