#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : 
            name(name), weapon(w) {}

void HumanA::attack( void ) {
    std::cout << name
              << " attacks with their " << weapon.getType()
              << std::endl;
}