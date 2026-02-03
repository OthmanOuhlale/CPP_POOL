#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string n, int grdToSn, int grdToEx)
    : _name(n), _signed(false), _gradeToSign(grdToSn), _gradeToExec(grdToEx) {
    if (_gradeToSign < 1 || _gradeToExec < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExec > 150)
        throw GradeTooLowException();
};

Form::Form(const Form& other)
    :  _name(other._name), _signed(other._signed),
    _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
};

Form& Form::operator=(const Form& other) {
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
};

Form::~Form() {};

std::string Form::getName( void ) const {
    return (_name);
};

bool Form::getSign( void ) const {
    return (_signed);
};

int Form::getGradeToSign( void ) const {
    return (_gradeToSign);
};

int Form::getGradeToExec( void ) const {
    return (_gradeToExec);
};

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
};

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade Is Too High";
};

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade Is Too Low";
};

std::ostream& operator<<(std::ostream& os, const Form& f) {

    os << "Name: " << f.getName() << std::endl
    << "Signed: " << f.getSign() << std::endl
    << "Grade to sign: " << f.getGradeToSign() << std::endl
    << "Grade to execute: " << f.getGradeToExec() << std::endl;

    return (os);
};