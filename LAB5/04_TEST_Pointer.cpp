#include <iostream>
using namespace std;

double f (double x){
    return (x - 1) * (x - 3);
}

void Distance (double (*fPtr) (double), double a, double b, double dx, double* Xmin , double* Ymin){
        
    for (double i = a; i <=b; i+=dx){
        if (fPtr(i) < *Ymin){
            *Xmin = i;
            *Ymin = f(i);
        } 
    }
}

int main(){
    double Xmin = 0., Ymin = 0.;
    double a = -1., b = 5., dx = 0.001;
    Distance(f, a, b, dx, &Xmin, &Ymin);
    cout << "Xmin: " << Xmin << endl 
         << " Ymin: " << Ymin << endl;
}