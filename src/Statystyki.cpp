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
void statystyki(int poprawne, int niepoprawne, int ilosc)
{
    int procent;
    std::cout << "Ilosc poprawnych odpowiedzi: " << poprawne << std::endl;
    std::cout << "Ilosc blednych odpowiedzi: " << niepoprawne << std::endl;
    procent = poprawne / ilosc * 100;
    std::cout << "Procent poprawnych odpowiedzi: " << procent << "%" << std::endl;
}
