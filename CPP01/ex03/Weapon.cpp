#include "Weapon.hpp"

Weapon::Weapon(std::string tp) : type(tp) {}

const std::string &Weapon::getType( void ) const {
    return (type);
}

void Weapon::setType(std::string tp) {
    type = tp;
}
