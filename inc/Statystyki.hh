#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

struct  Statystyka {
  int poprawne = 0;
  int niepoprawne = 0;
  int ilosc = 0;
  int procent = 0;
};

int Statystyki(int poprawne, int niepoprawne, int ilosc);

#endif
