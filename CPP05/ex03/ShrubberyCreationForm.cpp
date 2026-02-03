#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 72, 137), _target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
};

ShrubberyCreationForm::~ShrubberyCreationForm() {};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExec())
        throw GradeTooLowException();

    std::ofstream file((_target + "_shrubbery").c_str());
    file << "   ^   " << std::endl;
    file << "  ^^^  " << std::endl;
    file << " ^^^^^ " << std::endl;
    file << "   |   " << std::endl;
    file.close();
};
