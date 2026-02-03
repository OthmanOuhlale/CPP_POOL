#include "Zombie.hpp"

Zombie::Zombie(std::string nm) : name(nm) {}

Zombie::~Zombie( void ) {
    std::cout << "Zombie '" << name << "' is died.\n";
}

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
