#include "Zombie.hpp"

int main()
{
    Zombie *ZOMBIE = newZombie("bRANDOM");
    randomChump("foo");
    ZOMBIE->announce();
    delete(ZOMBIE);
}