#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    int n = 10;
    int i = 0;
    const Animal *animalito[n];
    // const Animal *animalito = new Cat[n];

    while (i < n)
    {
        if (i % 2)
            animalito[i] = new Dog();
        else
            animalito[i] = new Cat();
        i++;
    }
    i = 0;
    while(i < n)
    {
        delete animalito[i];
        i++;
    }
    // delete [] animalito; // cant be done compiler cries a lot
}