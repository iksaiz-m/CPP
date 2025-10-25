#ifndef BASE_HPP
#define BASE_HPP

// #include <cctype>
// #include <string.h>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

class Base
{
    public:
        virtual ~Base(); // public virtual destructor only
};

class A : public Base // empty classes that inherit from Base
{
};
class B : public Base
{
};
class C : public Base
{
};
#endif