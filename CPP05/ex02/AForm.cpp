#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string n, int grdToSn, int grdToEx)
    : _name(n), _signed(false), _gradeToSign(grdToSn), _gradeToExec(grdToEx) {
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExec > 150)
        throw GradeTooLowException();
};

AForm::AForm(const AForm& other)
    :  _name(other._name), _signed(other._signed),
    _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
};

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
};

AForm::~AForm() {};

std::string AForm::getName( void ) const {
    return (_name);
};

bool AForm::isSigned( void ) const {
    return (_signed);
};

int AForm::getGradeToSign( void ) const {
    return (_gradeToSign);
};

int AForm::getGradeToExec( void ) const {
    return (_gradeToExec);
};

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
};

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade Is Too High!";
};

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade Is Too Low!";
};

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form Not Signed!";
};

std::ostream& operator<<(std::ostream& os, const AForm& f) {

    os << "Name: " << f.getName() << std::endl
    << "Signed: " << f.isSigned() << std::endl
    << "Grade to sign: " << f.getGradeToSign() << std::endl
    << "Grade to execute: " << f.getGradeToExec() << std::endl;

    return (os);
};