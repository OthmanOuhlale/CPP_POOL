#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :  ClapTrap() {
    std::cout << "ScavTrap default constructor called";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap '" << _name << "' created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    *this = other;
    std::cout << "ScavTrap copied!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ScavTrap assigned!" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap '" << _name << "' destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& name) {
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << "Can't attack! ";
        std::cout << "(no HP or no energy)" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ScavTrap '" << _name << "' attacks '" << name << "',";
    std::cout << " causing " << _attackDamage << " points of damage!";
    std::cout << std::endl;
}

void ScavTrap::guardGate( void ) {
    std::cout << "ScavTrap '" << _name;
    std::cout << "' is now in Gate keeper mode!" << std::endl;
}
