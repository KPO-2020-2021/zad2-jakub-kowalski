#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Mnozenie dwoch liczb zespolonych") {
    LZespolona x, y,z ;
    
    x.re = 3;
    x.im = 2;

    y.re = 2;
    y.im = 3;

    z.re = 0;
    z.im = 13;
   
    CHECK(x*y == z);
}

TEST_CASE("Mnozenie liczby zespolonej przez (0+0i)") {
    LZespolona x, y,z ;
    
    x.re = 3;
    x.im = 2;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
   
    CHECK(x*y == z);
}

TEST_CASE("Mnozenie liczby zespolonej przez (1+0i)") {
    LZespolona x, y,z ;
    
    x.re = 2;
    x.im = 1;

    y.re = 1;
    y.im = 0;

    z.re = 2;
    z.im = 1;
   
    CHECK(x*y == z);
}

TEST_CASE("Mnozenie liczby zespolonej przez (0+1i)") {
    LZespolona x, y,z ;
    
    x.re = 3;
    x.im = 1;

    y.re = 0;
    y.im = 1;

    z.re = -1;
    z.im = 3;
   
    CHECK(x*y == z);
}

TEST_CASE("Mnozenie liczby zespolonej przez (1+1i)") {
    LZespolona x, y,z ;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;

    z.re = 0;
    z.im = 4;
   
    CHECK(x*y == z);
}


