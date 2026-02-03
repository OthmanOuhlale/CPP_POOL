#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}

// Constructor with name
ClapTrap::ClapTrap(std::string name) :
    name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copied!" << std::endl;
    *this = other;
}

// Copy assignment
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assigned!" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

// Attack
void ClapTrap::attack(const std::string& target) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ClapTrap " << name 
                  << " can't attack! (no HP or no energy)" << std::endl;
        return;
    }

    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

// Take damage
void ClapTrap::takeDamage(unsigned int amount) {
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;

    std::cout << "ClapTrap " << name 
              << " takes " << amount << " damage! (HP = " << hitPoints << ")" << std::endl;
}

// Repair
void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ClapTrap " << name 
                  << " can't repair! (no HP or no energy)" << std::endl;
        return;
    }

    energyPoints--;
    hitPoints += amount;

    std::cout << "ClapTrap " << name
              << " repairs itself, recovering " << amount 
              << " hit points! (HP = " << hitPoints << ")" << std::endl;
}

