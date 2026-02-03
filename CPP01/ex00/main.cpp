#include "Zombie.hpp"

int main()
{
    Zombie *z = newZombie("Foo1");
    z->announce();
    delete z;

    randomChump("Foo2");
    return (0);
}