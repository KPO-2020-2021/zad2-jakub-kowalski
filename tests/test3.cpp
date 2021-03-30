#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Porownanie dwoch liczb") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 2;
   
    CHECK(x == y);
}

TEST_CASE("Porownanie dwoch liczb minimalnie nierownych") {
    LZespolona x, y;
    
    x.re = 4;
    x.im = 6;

    y.re = 4.000000001;
    y.im = 2.000000001;
   
    CHECK_FALSE(x == y);
}

TEST_CASE("Porownanie dwoch roznych liczb") {
    LZespolona x, y;
    
    x.re = 2;
    x.im = 2;

    y.re = 2;
    y.im = 1;
   
    CHECK_FALSE(x == y);
}



