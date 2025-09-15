#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* x = new WrongCat(); 
// const Animal* k(i); // will not call copy constructor as it a pointer not an object, only one delete

delete (i);
i = j; // to make a copy we need to delete de malloc first to avoid leaks after

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
std::cout << x->getType() << " " << std::endl; // should print nothing as it calls to wronganimal which has no type
i->makeSound(); //will output the cat sound!
j->makeSound();
x->makeSound(); // will output wronganimal sound instead of MIAUU
// k->makeSound();
// k->getType();
meta->makeSound();
delete (j);
delete(meta);
// delete(k); // it can be k or i because it is a pointer
}