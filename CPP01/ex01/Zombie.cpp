#include "Zombie.hpp"

Zombie::Zombie( void ) : name("") {}

Zombie::~Zombie( void ) {
    std::cout << "Zombie '" << name << "' is died.\n";
}

void Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string n) {
    name = n;
}