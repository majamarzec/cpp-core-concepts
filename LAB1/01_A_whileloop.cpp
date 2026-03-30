#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    
    while ( true )
    {   
    i++;
    if (i%2 == 0) {
        continue;
    }

    if (i == 9) {
        break;
    }
    cout << i << endl;
    }
    return 0;
}