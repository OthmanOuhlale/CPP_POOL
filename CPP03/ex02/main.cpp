#include "FragTrap.hpp"

int main() {
    ClapTrap a("Othman");
    std::cout << "-------" << std::endl;
    FragTrap b("Enemy");
    std::cout << "-------" << std::endl;
    a.attack("Enemy");
    b.takeDamage(3);

    b.attack("Othman");
    a.takeDamage(5);

    a.beRepaired(4);
    b.beRepaired(3);

    b.highFivesGuys();
    std::cout << "-------" << std::endl;
    return 0;
}
