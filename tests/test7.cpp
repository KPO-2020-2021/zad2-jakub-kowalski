#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test +="){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 1;

    z.re = 2;
    z.im = 2;
    
    CHECK((x+=y) == z);
}

TEST_CASE("Test += (0+0i)"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;
    
    CHECK((x+=y) == z);
}

TEST_CASE("Test += (0+0i) + (0+0i)"){
    LZespolona x, y, z;

    x.re = 0;
    x.im = 0;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;
    
    CHECK((x+=y) == z);
}

TEST_CASE("Test += (0.00001+0.00001i)"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 2;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 2.00001;
    z.im = 2.00001;
    
    CHECK((x+=y) == z);
}