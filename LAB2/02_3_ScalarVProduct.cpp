//zadanie 3 seria 2
//kąt otwarcia między wektorami
//programowanie funkcyjne

#include <iostream>
#include <cmath>
using namespace std;



float Length(float vx, float vy){
    return sqrt(pow(vx, 2.) + vy*vy); // sqrt to funkcja przeciązona (float, double) + probuje jednokrotnie zrobic konwersje np long double -> double, tu nie działa v ** 2 ! tylko pow lub iloczyn
}

float DotProduct(float v1x, float v1y, float v2x, float v2y){
    return v1x * v2x + v1y * v2y;
}

float Angle(float v1x, float v1y, float v2x, float v2y){
    float CosAngle = DotProduct(v1x, v1y, v2x, v2y) / (Length(v1x, v1y) * Length(v2x, v2y));
    return acos( CosAngle ) * 180. / M_PI;   
}

int main() {
    float v1x = 2., v1y = 0.;
    float v2x = 0., v2y = 2.;

    cout << Angle(v1x, v1y, v2x, v2y) << endl;
    return 0;
}


