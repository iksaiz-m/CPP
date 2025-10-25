#include "Base.hpp"

static Base* generate(void)
{
    std::srand(std::time(0));          // seed (can be made once in the main)
    int i = std::rand() % 3;           // 0 or 1, 2 random
    if (i == 0)
    {
        std::cout << "Type A created" << std::endl;
        return(new A());
    }
    if (i == 1)
    {
        std::cout << "Type B created" << std::endl;
        return(new B());
    }
    else
    {
        std::cout << "Type C created" << std::endl;
        return(new C());
    }
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p)) // if the cast returns true then the type is that one
        std::cout << "Type is A" << std::endl;
    if(dynamic_cast<B*>(p))
        std::cout << "Type is B" << std::endl;
    if(dynamic_cast<C*>(p))
        std::cout << "Type is C" << std::endl;
}
void identify(Base& p)
{
    // if(dynamic_cast<A &>(p)) // cant be compared directly in one if like the other
    //     std::cout << "Type is A" << std::endl;
    // if(dynamic_cast<B&>(p))
    //     std::cout << "Type is B" << std::endl;
    // if(dynamic_cast<C&>(p))
    //     std::cout << "Type is C" << std::endl;
    try
    {
        // Base& instance = dynamic_cast<A &>(p); // needs to be initialized to something but cant because its a reference
        (void)dynamic_cast<A&>(p);
        std::cout << "Type is A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type is B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
     try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type is C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(void)
{
    Base* instance = generate();
    identify(instance);
    identify(*instance);
    delete (instance);
    return (0);
}