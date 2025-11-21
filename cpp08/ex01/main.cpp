#include "Span.hpp"

int main(void)
{
    try
    {
        Span sp(5);
        // sp.addNumber(6);
        // sp.addNumber(3);
        // sp.addNumber(17);
        // sp.addNumber(9);
        // sp.addNumber(11);
        // std::cout << sp[0] << std::endl;
        // std::cout << sp[1] << std::endl;
        // std::cout << sp.shortestSpan() << std::endl;
        // std::cout << sp.longestSpan() << std::endl;
        // int x = 0;
        // size_t len = 10;
        // std::srand(std::time(0));
        // while(x < 10)
        // {
        //     // int i = std::rand() % 2;
        //     // iter(sp, len, sp.addNumber(i)); // doesnt work because it expects a result from addNumber and returns void, is not a call to the function
        //     // iter(sp, 1, &{ sp.addNumber(x)});
        //     // iter(sp, 1, [&](int value) {sp.addNumber(value);});
        //     x++;
        // }
        void randomize(int& value)
        {
            value = std::rand() % 100;
        }

// Uso:
iter(sp, 1, randomize);

        iter(sp, 1, [&](int& value) { 
    value = std::rand() % 100; // asignar un valor aleatorio
});

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}