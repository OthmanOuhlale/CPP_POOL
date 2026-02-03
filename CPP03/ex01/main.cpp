#include "ScavTrap.hpp"

int main() {
    ClapTrap a("Othman");
    std::cout << "-------" << std::endl;
    ScavTrap b("Enemy");
    std::cout << "-------" << std::endl;
    a.attack("Enemy");
    b.takeDamage(3);

    b.attack("Othman");
    a.takeDamage(20);

    a.beRepaired(10);
    b.beRepaired(3);

    b.guardGate();
    std::cout << "-------" << std::endl;
    return 0;
}
