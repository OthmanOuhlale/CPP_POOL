#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    private:

        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExec;

    public:

        Form(const std::string n, int grdToSn, int grdToEx);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        std::string getName( void ) const;
        bool        getSign( void ) const;
        int         getGradeToSign( void ) const;
        int         getGradeToExec( void ) const;
        void        beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
