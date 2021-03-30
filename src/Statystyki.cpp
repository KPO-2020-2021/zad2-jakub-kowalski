#include <iostream>
#include "Statystyki.hh"


/*!
* Podaje statystyki testu
* Argumenty:
*   poprawne - ilosc poprawnych odpowiedzi
*   niepoprawne - ilosc blednych odpowiedzi
* Zwraca:
*   Liczbe poprawnych i blednych odpowiedzi oraz procent poprawnych odpowiedzi
*/
int Statystyki(int poprawne, int niepoprawne, int ilosc)
{
    Statystyka stat;
    std::cout << "Ilosc poprawnych odpowiedzi: " << std::noshowpos << poprawne << std::endl;
    std::cout << "Ilosc blednych odpowiedzi: " << std::noshowpos << niepoprawne << std::endl;
    std::cout << "Ilosc pytan: " << std::noshowpos << ilosc << std::endl;
    stat.procent = 100 * poprawne / ilosc;
    std::cout << "Procent poprawnych odpowiedzi: " << std::noshowpos << stat.procent << "%" << std::endl;

    return stat.procent;
}
