#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    std::string name;
    int grade;
public:
    Bureaucrat();
    ~Bureaucrat();
    std::string getName( void ) const;
    int getGrade( void ) const;
    void increment();
    void decrement();
};

#endif