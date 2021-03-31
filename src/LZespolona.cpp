#include <cmath>
#include <iostream>
#include <stdexcept>
#include "LZespolona.hh"


/*!
 * Porownuje czy liczba wczytana jest taka sama jak oczekiwany wynik.
 */
bool  operator == (LZespolona  Skl1,  LZespolona  Skl2)
{
  if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
  {                          
    return true;
  }                                                                
  else
  {                                                                    
    return false; 
  }                                                                                  
}


bool  operator != (LZespolona  Skl1,  LZespolona  Skl2)
{
  if ((Skl1.re != Skl2.re) || (Skl1.im != Skl2.im))
  {                         
    return true;
  }                                                                
  else
  {                                                                    
    return false; 
  }                                                                                  
}


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



LZespolona operator += (LZespolona &Skl1, LZespolona const &Skl2)
{
  LZespolona  Wynik;
  Wynik.re = 0;
  Wynik.im = 0;

  Wynik.re = Wynik.re + Skl1.re + Skl2.re;
  Wynik.im = Wynik.im + Skl1.im + Skl2.im;
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

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
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

  if((pow(Skl2.re, 2) + pow(Skl2.im, 2)) == 0)
  {
    throw std::runtime_error("Proba dzielenia przez zero");
  }
  else
  {
    Wynik.re = ((Skl1.re * Skl2.re) + (Skl1.im * Skl2.im)) / (pow(Skl2.re, 2) + pow(Skl2.im, 2));
    Wynik.im = ((Skl2.re * Skl1.im) - (Skl1.re * Skl2.im)) / (pow(Skl2.re, 2) + pow(Skl2.im, 2));
    return Wynik;
  }
}


LZespolona  operator /= (LZespolona &Skl1, LZespolona const &Skl2)
{
  LZespolona  Wynik;
  Wynik.re = 0;
  Wynik.im = 0;

  if((pow(Skl2.re, 2) + pow(Skl2.im, 2)) == 0)
  {
    throw std::runtime_error("Proba dzielenia przez zero");
  }
  else
  {
    if((Wynik.re != 0) && (Wynik.im != 0))
    {
      if(((Skl1.re * Skl2.re) + (Skl1.im * Skl2.im)) / (pow(Skl2.re, 2) + pow(Skl2.im, 2)) && (Wynik.im / ((Skl2.re * Skl1.im) - (Skl1.re * Skl2.im)) / (pow(Skl2.re, 2) + pow(Skl2.im, 2))) == 0)
      {
        throw std::runtime_error("Proba dzielenia przez zero");
      }
      else
      {
        Wynik.re = (Wynik.re / ((Skl1.re * Skl2.re) + (Skl1.im * Skl2.im)) / (pow(Skl2.re, 2) + pow(Skl2.im, 2)));
        Wynik.im = (Wynik.im / ((Skl2.re * Skl1.im) - (Skl1.re * Skl2.im)) / (pow(Skl2.re, 2) + pow(Skl2.im, 2)));
      }
    }
    else
    {
      Wynik.re = ((Skl1.re * Skl2.re) + (Skl1.im * Skl2.im)) / (pow(Skl2.re, 2) + pow(Skl2.im, 2));
      Wynik.im = ((Skl2.re * Skl1.im) - (Skl1.re * Skl2.im)) / (pow(Skl2.re, 2) + pow(Skl2.im, 2));
    }
    
    return Wynik;
  }
}


/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia - liczba rzeczywista.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double  Skl2)
{
  if (Skl2 == 0)
  {
    throw std::runtime_error("Proba dzielenia przez zero");
  }
  LZespolona  Wynik;
  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
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

void arg (LZespolona z)
{
  double fi;

  if(z.re > 0)
  {
    fi = atan2(z.im, z.re);
  }

  if(z.re < 0)
  {
    fi = atan2(z.im, z.re) + M_PI;
  }
  
  if(z.re == 0)
  {
    if(z.im > 0)
    {
      fi = M_PI/2;
    }
    if(z.im < 0)
    {
      fi = -1 * M_PI/2;
    }
    if(z.im == 0)
    {
      throw std::runtime_error("Argument nieokreslony.");
    }
  }

  std::cout << "Argument glowny fi wynosi: " << fi << std::endl;
}