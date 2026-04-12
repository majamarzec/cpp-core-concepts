#include <iostream>
using namespace std;

double f (double x){
    return (x - 1) * (x - 3);
}

void Distance (double a, double b, double dx, double& Xmin , double& Ymin){
    
    // nie zadziałało, bo miałam indeks typu int a tu musi być typu doble!!
    
    for (double i = a; i <=b; i+=dx){
        if (f(i) < Ymin){
            Xmin = i;
            Ymin = f(i);
        } 
    }
}
int main(){
    double Xmin = 0., Ymin = 0.;
    double a = -1., b = 5., dx = 0.001;
    Distance(a, b, dx, Xmin, Ymin);
    cout << "Xmin: " << Xmin <<endl << " Ymin: " << Ymin << endl;
}