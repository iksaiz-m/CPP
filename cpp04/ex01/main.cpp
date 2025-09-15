#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// // const Animal* x(i); // will not call copy constructor as it a pointer not an object, only one delete

// delete (i);
// i = j; // to make a copy we need to delete de malloc first to avoid leaks after

// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// j->makeSound();
// // x->makeSound();
// // x->getType();
// meta->makeSound();
// delete (j);
// delete(meta);
// delete(x); // it can be x or i because it is a pointer
    int n = 10;
    int i = 0;
    const Animal *animalito = new Animal[n];
    // const Animal *animalito = new Cat[n];

    while (i < n)
    {
        animalito[i].getType();
        // else
        //     Animal *pepe = new Cat();
        i++;
    }
    delete [] animalito;
}