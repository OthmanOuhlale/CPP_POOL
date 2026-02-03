#include "Bureaucrat.hpp"

int main( void ) {
    try
    {
        Bureaucrat b("Othman", 1);
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}