#include <iostream>
using namespace std;

int SumDigits (int n){
 	if (n == 0)
    	return 0;
	else {
    	return n % 10 + SumDigits(n / 10); //jeden slash ucina ostatnia cyfre jak podzielimy na 10
	}
}


int FiboRec(int N)
{
	if (N == 0)
    	return 0;
	if (N == 1)
    	return 1;
	return FiboRec(N - 1) + FiboRec(N - 2);
}