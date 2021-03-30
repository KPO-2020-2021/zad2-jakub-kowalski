#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Odejmowanie dwoch liczb") {
    LZespolona x, y,z ;
    
    x.re = 1;
    x.im = -2;

    y.re = 3;
    y.im = 1;

    z.re = -2;
    z.im = -3;
   
    CHECK(x-y == z);
}


TEST_CASE("Odejmowanie (0+0i)") {
    LZespolona x, y,z ;
    
    x.re = 3;
    x.im = 5;

    y.re = 0;
    y.im = 0;

    z.re = 3;
    z.im = 5;
   
    CHECK(x-y == z);
}

TEST_CASE("Odejmowanie (0.0+0.0i)") {
    LZespolona x, y,z ;
    
    x.re = 2;
    x.im = 1;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 2;
    z.im = 1;
   
    CHECK(x-y == z);
}

TEST_CASE("Odejmowanie (0.00001+0.00001i)") {
    LZespolona x, y,z ;
    
    x.re = 1;
    x.im = 1;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.99999;
    z.im = 0.99999;
   
    CHECK(x-y == z);
}

