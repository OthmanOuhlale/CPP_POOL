#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        std::srand(std::time(NULL));
        Bureaucrat  boss("Boss", 1);
        Intern      someRandomIntern;
        AForm*      form1;
        AForm*      form2;

        form1 = someRandomIntern.makeForm("robotomy request", "Bender");
        boss.signForm(*form1);
        boss.executeForm(*form1);
        delete form1;

        form2 = someRandomIntern.makeForm("unkown form", "unknown");
        delete form2;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
