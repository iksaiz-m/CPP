#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

    // const AAnimal *animalito = new AAnimal(); // cant because is abstract
    const AAnimal *gabriel = new Dog();
    gabriel->makeSound();
    delete (gabriel);
    // const Animal *animalito = new Cat[n];

    // while (i < n)
    // {
    //     if (i % 2)
    //         animalito[i] = new Dog();
    //     else
    //         animalito[i] = new Cat();
    //     i++;
    // }
    // i = 0;
    // while(i < n)
    // {
    //     delete animalito[i];
    //     i++;
    // }
    // delete [] animalito; // cant be done compiler cries a lot
}