#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "1 - Debug: ";
    harl.complain("DEBUG");

    std::cout << "2 - Info: ";
    harl.complain("INFO");

    std::cout << "3 - Warning: ";
    harl.complain("WARNING");

    std::cout << "4 - ERROR: ";
    harl.complain("ERROR");

    return (0);
}

// int main(int ac, char **av)
// {
//     if (ac != 2)
//     {
//         std::cout << "Usage: ./HARL <level>" << std::endl;
//         return (1);
//     }
//     std::string input = av[1];
//     Harl harl;
//     harl.complain(input);
//     return (0);
// }