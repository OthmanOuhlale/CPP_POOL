#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        std::srand(std::time(NULL));
        Bureaucrat boss("Boss", 1);

        // ---------- Presidential Pardon ----------
        PresidentialPardonForm pardon("Arthur");
        boss.signForm(pardon);
        boss.executeForm(pardon);

        std::cout << "-----------------------------" << std::endl;

        // ---------- Robotomy Request ----------
        RobotomyRequestForm robotomy("Marvin");
        boss.signForm(robotomy);
        boss.executeForm(robotomy);

        std::cout << "-----------------------------" << std::endl;

        // ---------- Shrubbery Creation ----------
        ShrubberyCreationForm shrub("garden");
        boss.signForm(shrub);
        boss.executeForm(shrub);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
