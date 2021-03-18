#include <iomanip>
#include <iostream>
#include "WyrazenieZesp.hh"

void Wyswietl(LZespolona Skl1)
{
    std::cout << "(" << std::noshowpos << Skl1.re << std::showpos << Skl1.im << "i)";
}


/*!
* Wyswietla operator wyrazenia
*/
std::ostream & operator << (std::ostream &s, Operator Op)
{
    switch (Op)
    {
        case Op_Dodaj:
        return s << '+';
        break;

        case Op_Odejmij:
        return s << '-';
        break;

        case Op_Mnoz:
        return s << '*';
        break;

        case Op_Dziel:
        return s << '/';
        break;

        default:
        return s;
        break;
    }
}


/*!
* Wyswietla wyrazenie zespolone
*/
std::ostream & operator << (std::ostream & s, WyrazenieZesp Wyrz)
{
    return s << Wyrz.Arg1 << Wyrz.Op << Wyrz.Arg2;
}


/*!
* Wczytuje operator wyrazenia
*/
std::istream & operator >> (std::istream & strm, Operator &Op)
{
    char znak;
    strm >> znak;
    switch (znak)
    {
        case '+':
        Op=Op_Dodaj;
        break;

        case '-':
        Op=Op_Odejmij;
        break;

        case '*':
        Op=Op_Mnoz;
        break;

        case '/':
        Op=Op_Dziel;
        break;

        default:
        strm.setstate(std::ios::failbit);
        break;
    }

    return strm;
}


/*!
* Wczytuje wyrazenie zespolone
*/
std::istream & operator >> (std::istream &strm, WyrazenieZesp &Wyrz)
{
    strm >> Wyrz.Arg1 >> Wyrz.Op >> Wyrz.Arg2;
    return strm;
}

LZespolona Oblicz (WyrazenieZesp &WyrZ)
{
    LZespolona Wynik;

    switch(WyrZ.Op)
    {
    case Op_Dodaj:
        Wynik = WyrZ.Arg1 + WyrZ.Arg2;
        break;

    case Op_Odejmij:
        Wynik = WyrZ.Arg1 - WyrZ.Arg2;
        break;

    case Op_Mnoz:
        Wynik = WyrZ.Arg1 * WyrZ.Arg2;
        break;

    case Op_Dziel:
        Wynik = WyrZ.Arg1 / WyrZ.Arg2;
        break;
    }

    return Wynik;
}