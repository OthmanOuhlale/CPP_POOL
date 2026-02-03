#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {};

Intern::Intern(const Intern& other) {
    (void)other;
};

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return (*this);
};

Intern::~Intern() {};

AForm* Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
};

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
};

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
};

AForm*    Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string names[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    AForm* (Intern::*factory[3]) (const std::string&) = {
        &Intern::createPresidential,
        &Intern::createRobotomy,
        &Intern::createShrubbery
    };

    int i = 0;
    while (i < 3)
    {
        if (formName == names[i])
        {
            std::cout << "Intern create " << formName << std::endl;
            return (this->*factory[i])(target);
        }
        i++;
    }
    std::cout << "Intern cannot create this Form" << std::endl;
    return (NULL);
};
