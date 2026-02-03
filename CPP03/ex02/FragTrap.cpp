#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap default constructor called";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap '" << _name << "' created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "FragTrap assigned!" << std::endl;
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap '" << _name << "' destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& name) {
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "FragTrap " << _name << "Can't attack! ";
        std::cout << "(no HP or no energy)" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "FragTrap '" << _name << "' attacks '" << name << "',"
            << " causing " << _attackDamage << " points of damage!"
            << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name 
            << " requests a positive high five!"
            << std::endl;
}

