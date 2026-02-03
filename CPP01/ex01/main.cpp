#include "Zombie.hpp"

int main( void )
{
    Zombie      *z;
    std::string name;
    int         N;
    int         i;

    name = "ZOO";
    N = 5;
    z = zombieHorde(N, name);
    i = 0;
    while (i < N)
    {
        z->announce();
        i++;
    }
    delete []z;
    return (0);
}
