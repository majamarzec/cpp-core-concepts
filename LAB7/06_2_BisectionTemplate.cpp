#include <cmath>
#include <limits>
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T> 
T myexp( T x ) {
  return exp(-x) - x;
}

template <typename T>
T bisection ( T x1, T x2, T eps )
{
  T y1 = myexp (x1);
  while ( fabs (x2 - x1) > eps )
  {
    T x = (x1 + x2) / 2.;
    T y = myexp (x);
    // ten typ zera juz jest troche purystyczny, tez moznaby zrzutowac 2.
    if ( y*y1 > T(0) ) {
      x1 = x;
      y1 = y;
    }
    else
      x2 = x;
  }
  return (x1 + x2) / 2.;

}

// uogolnienie wciaganej funkcji - wskaznik funkcyjny

template <typename T>
T bisection2 ( T (*funPtr) (T), T x1, T x2, T eps )
{
  T y1 = funPtr (x1);
  while ( fabs (x2 - x1) > eps )
  {
    T x = (x1 + x2) / T(2.);
    T y = funPtr (x);
    if ( y*y1 > T(0) ) {
      x1 = x;
      y1 = y;
    }
    else
      x2 = x;
  }
  return (x1 + x2) / T(2.);
}

// dwa typy argumentow 
// dedukowanie ogolnych obiektow
// typ F to typ wskaźnika

template<typename T, typename F>
T bisection3 ( F funPtr , T x1, T x2, T eps )
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


int main ()
{
  cout << setprecision ( numeric_limits<double>::max_digits10 )
       << bisection ( 0. , 1. , numeric_limits<double>::epsilon() ) << endl; // 0. i 1. to znaczy ze w doublach
       // << bisection ( 0.f , 1.d , numeric_limits<double>::epsilon() ) // tu jeden z argumentow jest innego typu co jest nieakceptowalne przez szablon, ktorego wszystkie argumenty sa tylu T
       // double jest z lepszą precyzją

  cout << setprecision ( numeric_limits<double>::max_digits10 )
       << bisection ( 0.f , 1.f , numeric_limits<float>::epsilon() ) << endl;

  // do tego przypiszemy sobie myexp
  double (* myFunPtrD) (double) = myexp; // obsluguje tylko doubla
  float (* myFunPtrF) (float) = myexp; // obsluguje tylko doubla

  cout << setprecision ( numeric_limits<double>::max_digits10 )
       << bisection2 ( myFunPtrD, 0. , 1. , numeric_limits<double>::epsilon() ) << endl;

  cout << setprecision ( numeric_limits<double>::max_digits10 )
       << bisection2 ( myFunPtrF, 0.f , 1.f , numeric_limits<float>::epsilon() ) << endl;

 // anie nie mozemy mu wrzucic szablonu bezz zdefiniowanego typu, czyli po prostu myexp
  cout << setprecision ( numeric_limits<double>::max_digits10 )
       << bisection3 ( myFunPtrD, 0. , 1. , numeric_limits<double>::epsilon() ) << endl;

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