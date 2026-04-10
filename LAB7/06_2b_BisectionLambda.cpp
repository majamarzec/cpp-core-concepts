#include <cmath>
#include <limits>
#include <iostream>
#include <iomanip>
using namespace std;



template<typename T, typename F>
T bisection3 ( F& funPtr , T x1, T x2, T eps )
{
  T y1 = funPtr (x1);
  while ( fabs (x2 - x1) > eps )
  {
    T x = (x1 + x2) / 2.;
    T y = funPtr (x);
    if ( y*y1 > T(0) ) {
      x1 = x;
      y1 = y;
    }
    else
      x2 = x;
  }
  return (x1 + x2) / 2.;
}

// od c++ 20
//template<typename T>
//T bisection3 ( auto &funPtr , T x1, T x2, T eps )
// & - pracujemy na referencji (oryginale)

// kazda lambda ma inny typ
int main ()
{
  auto myLamD = [] (double x) -> double {return exp(-x) - x; } ;
  auto myLamF = [] (float x) -> float {return exp(-x) - x; } ;

  // do tego przypiszemy sobie myexp
  double (* myFunPtrD) (double) = myLamD; // obsluguje tylko doubla
  float (* myFunPtrF) (float) = myLamF; // obsluguje tylko doubla

 // anie nie mozemy mu wrzucic szablonu bezz zdefiniowanego typu, czyli po prostu myexp
  cout << setprecision ( numeric_limits<double>::max_digits10 )
       << bisection3 ( myFunPtrD , 0. , 1. , numeric_limits<double>::epsilon() ) << endl;

  cout << setprecision ( numeric_limits<double>::max_digits10 )
       << bisection3 ( myFunPtrF, 0.f , 1.f , numeric_limits<float>::epsilon() ) << endl;

  // cout << bisection ("abc", "def", "ghi" ); nie pojdzie dla roznych typow i dla zlego wykorzystania operatorow

  // numeric_limits<double>::epsilon() to tez double
  // to istotne bo w domniemanym type daliśmy dla wszystkich argumentow ten sam typ
  
  /* typedef {oryginalny typ} {alias}      = alias na typ (skrotowiec) 

    typedef  numeric_limits<double>  limD ;

    cout << setprecision ( limD::max_digits10 )
        << bisection ( 0. , 1. , limD::epsilon() ) << endl;
  */  

  return 0;
}

//lamdbe mozna wepchnac do wskaźnika funkcyjnego tylko gdy capture jest pusty ([])
// funkcje nie potrafia tego, wiec to sie nie uda
// to jest wieksza mozliwosc 