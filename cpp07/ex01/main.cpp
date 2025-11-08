#include "iter.hpp"

int main()
{
    //non constant
    char str[] = "hola";
    iter(str, 4, printElement<char>); // tells the compiler the function will work with a char
    iter(str, 4, toUpper<char>);
    iter(str, 4, printElement<char>);
    std::cout << std::endl;
    // constant
    const int nums[] = {1, 2, 3, 4, 5};
    // const char pepe[] = "hola";
    // iter(pepe, 4, toUpper<char>); // cant work because it will try to modify the const char
    iter(nums, 5, printElement<int>); // tells the compiler the function will work with int
    std::cout << std::endl;

    return 0;
}