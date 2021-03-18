#include <iomanip>
#include <iostream>
#include "WyrazenieZesp.hh"

void Wyswietl(LZespolona Skl1)
{
    std::cout << Skl1.re << std::showpos << Skl1.im;
}