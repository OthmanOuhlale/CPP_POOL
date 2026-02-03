#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "----- Test 1: Valid bureaucrat & form -----" << std::endl;
    try
    {
        Bureaucrat b1("Alice", 10);
        Form f1("TaxForm", 20, 30);

        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;

        b1.signForm(f1);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n----- Test 2: Grade too low to sign -----" << std::endl;
    try
    {
        Bureaucrat b2("Bob", 50);
        Form f2("SecretForm", 10, 20);

        b2.signForm(f2);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

