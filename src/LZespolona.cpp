#include <cmath>
#include <iostream>
#include "LZespolona.hh"


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1, LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1, LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}


/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1, LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl1.im) - (Skl2.re * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl2.re * Skl1.im);
  return Wynik;
}


/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1, LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = ((Skl1.re * Skl2.re) + (Skl1.im * Skl2.im)) / (pow(Skl2.re, 2)+pow(Skl2.im, 2));
  Wynik.im = ((Skl2.re * Skl1.im) - (Skl1.re * Skl2.im)) / (pow(Skl2.re, 2)+pow(Skl2.im, 2));
  return Wynik;
}


/*!
* Wyswietla liczbe zespolona
*/
std::ostream & operator << (std::ostream &s, LZespolona Skl1)
{
    return s << "(" << std::noshowpos << Skl1.re << std::showpos << Skl1.im << "i)";
}


/*!
* Wczytuje liczbe zespolona
*/
std::istream & operator >> (std::istream &strm, LZespolona &Skl1)
{
  char znak;
  strm >> znak;
  if (znak != '('){
    strm.setstate(strm.failbit);
  }

  strm >> Skl1.re;
  strm >> Skl1.im;
  strm >> znak;

  if (znak!='i'){
    strm.setstate(strm.failbit);
  }

  strm >> znak;
  if (znak!=')'){
    strm.setstate(strm.failbit);
  }
  
  return strm;
}
