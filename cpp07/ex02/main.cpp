#include "Array.hpp"

int main()
{
    // the type is needed in between <>
    try
    {
        Array<int> intarray;
        Array<int> meme(5);
        // meme[0] = 45;

        Array<int> xd(meme);
        // Array<char> pepe(xd); cant be made because Type and Type arent the same
        intarray = meme;
        intarray[1] = 17;
        // size_t len = meme.size();
        size_t len2 = xd.size();
        // std::cout << "len meme: " <<len << std::endl;
        std::cout << "len xd: " << len2 << std::endl;
        // std::cout << "xd[0]: " << xd[0] << std::endl;
        // std::cout << "intarray[0]: " << intarray[0] << std::endl;
        // std::cout << "intarray[1]: " << intarray[1] << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}