#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap default constructor called";
}

ClapTrap::ClapTrap(const std::string& name) {
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap '" << _name << "' created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap assigned!" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap '" << _name << "' destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& name) {
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "ClapTrap '" << _name << "' can't attack! ";
        std::cout << "(no HP or no energy)" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ClapTrap '" << _name << "' attacks '" << name << "',";
    std::cout << " causing " << _attackDamage << " points of damage!";
    std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitPoints -= amount;
    if (_hitPoints <= 0)
        _hitPoints = 0;
    std::cout << "ClapTrap '" << _name << "' takes " << amount;
    std::cout << " damage!" << " (HP: " << _hitPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap '" << _name << "' cannot repair! ";
        std::cout << "(no HP or no energy)" << std::endl;
        return ;   
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap '" << _name << "' repairs it self!";
    std::cout << " (HP: " << _hitPoints << ")" << std::endl;
}
