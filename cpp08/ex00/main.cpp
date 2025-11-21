#include "easyfind.hpp"

int main()
{
    // the type is needed in between <>
    try
    {
        Array<int> meme(5);
        for (size_t i = 0; i < meme.size(); i++)
            meme[i] = int(i);
        // meme[0] = 15;
        // meme[1] = 40;
        // meme[2] = 27;
        // meme[3] = 15;
        // meme[4] = 50;
        std::cout << easyfind(meme, 15) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}