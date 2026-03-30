#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char randomletter () {
  return rand() % ('z' + 1 - 'a') + 'a' ;
}

int main () {
  srand ( time(NULL) );
  char secretletter = randomletter();
  char userletter;

  cout << "Zgadnij litere (mala), masz na to 5 prob.\n";
  for (int i = 0; i < 5; i++) {
    cout << "Proba " << i + 1 << ": ";
    cin >> userletter;
    
    if (userletter == secretletter){
	     cout <<"Gratulację, zgadłe/aś" << endl;
	     return 0;
    }

    else if ((userletter > secretletter) && (userletter <= 'z')) {
 	     cout << "Zbyt późna litera" << endl;
    }

    else if ((userletter < secretletter) && (userletter >= 'a')) {
	     cout << "Zbyt wczesna litera" << endl;
    }
    else {
  	     cout << "Niepoprawny znak!" << endl;
    }
  }
  cout << "Koniec prob, nie zgadle/as..." << endl;
  return 0;
}


