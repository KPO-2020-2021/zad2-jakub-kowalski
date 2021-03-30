#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test sumowania"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE("Dodawanie (0+0i)"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 3;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 3;
    
    CHECK(x+y == z);
}

TEST_CASE("Dodawanie (0.0+0.0i)"){
    LZespolona x, y, z;

    x.re = 1.1;
    x.im = 1.2;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 1.1;
    z.im = 1.2;

    CHECK(x+y == z);
}

TEST_CASE("Dodawanie (0.00001+0.00001i)"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 4;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 2.00001;
    z.im = 4.00001;
    
    CHECK(x+y == z);
}

