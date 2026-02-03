#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:

        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExec;

    public:

        AForm(const std::string n, int grdToSn, int grdToEx);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        std::string getName( void ) const;
        int         getGradeToSign( void ) const;
        int         getGradeToExec( void ) const;
        bool        isSigned( void ) const;

        void                beSigned(const Bureaucrat& b);
        virtual void        execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
