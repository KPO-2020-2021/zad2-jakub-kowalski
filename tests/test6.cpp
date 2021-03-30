#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "Statystyki.hh"

TEST_CASE("1. Init Quiz latwe"){
    
    Statystyka stat;

    stat.poprawne = 2;
    stat.niepoprawne = 2;
    stat.ilosc = 4;

    int oczekiwany_wynik = 50;

    CHECK(oczekiwany_wynik == Statystyki(stat.poprawne, stat.niepoprawne, stat.ilosc));
}