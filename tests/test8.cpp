#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test /=") {
    LZespolona x, y, z;
    
    x.re = 3;
    x.im = 3;

    y.re = 1;
    y.im = 1;

    z.re = 3;
    z.im = 0;
 
   CHECK((x/=y) == z);
}

TEST_CASE("Test /= - zero w mianowniku") {
    LZespolona x, y;
    
    x.re = 0;
    x.im = 0;

    y.re = 0;
    y.im = 0;
 
   WARN_THROWS(x/=y);
}