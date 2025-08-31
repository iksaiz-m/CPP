#include <iostream>
#include <cctype>
#include <string.h>
#include <sstream>
#include <iomanip>
int main()
{
    std::string brain = "HI THIS IS BRAIN";

    // std::string *stringPTR = &brain;
    std::string *stringPTR;
    stringPTR = &brain;
    //can be done both ways because it is a pointer, also it can be re-assinged again to another thing
    
    std::string &stringREF = brain;
    // std::string &stringREF;
    // stringREF = brain;
    // cant be done because it is a reference and it needs to be done at the moment of initialization
    // also references cant be asigned to NULL like a pointer can
    // you cant also do double references like with pointer to a pointer **str
    std::cout << "memory adress: " << &brain << std::endl;
    std::cout << "memory adress: " << &stringPTR << std::endl;
    std::cout << "memory adress: " << &stringREF << std::endl;
    std::cout << "normal value: " << brain << std::endl;
    std::cout << "normal value: " << stringPTR << std::endl;
    std::cout << "normal value: " << stringREF << std::endl;


}