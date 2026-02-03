#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./HARL <level>" << std::endl;
        std::cout << "--> Levels: DEBUG | INFO | WARNING | ERROR\n";
        return (1);
    }

    std::string input = av[1];
    Harl harl;
    harl.complain(input);

    return (0);
}