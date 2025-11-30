#include "Span.hpp"


int randomNumber()
{
    return(std::rand() % 100);
}

int main(void)
{
    // try
    // {
    //     Span sp(5);
    //     sp.addNumber(6);
    //     sp.addNumber(3);
    //     sp.addNumber(17);
    //     sp.addNumber(9);
    //     sp.addNumber(11);
    //     // int x = 0;
    //     // size_t len = 10;
    //     // std::srand(std::time(0));
    //     // while(x < 5)
    //     // {
    //     //     sp.addNumber(randomNumber());
    //     //     std::cout << sp[x] << std::endl;
    //     //     x++;
    //     // }
    //     std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    //     std::cout << "Longest: " << sp.longestSpan() << std::endl;
    
    //     // iter(sp, 1, randomize);
    // //     iter(sp, 1, (int& value)
    // //     {
    // // value = std::rand() % 100; // asignar un valor aleatorio
    // //     });
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    try
    {
        std::srand(std::time(0));
        Span sp(100);
        int tmp[100];
        for (int i = 0; i < 15; i++)
        tmp[i] = rand() % 1000;

        sp.addRange(tmp, tmp + 15);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    






    
    return (0);
}


