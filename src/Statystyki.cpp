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
void statystyki(int poprawne, int niepoprawne)
{
    int wynik;
    std::cout << "Ilosc poprawnych odpowiedzi: " << poprawne << std::endl;
    std::cout << "Ilosc blednych odpowiedzi: " << niepoprawne << std::endl;
    wynik = poprawne / 4 * 100;
    std::cout << "Procent poprawnych odpowiedzi: " << wynik << "%" << std::endl;
}
