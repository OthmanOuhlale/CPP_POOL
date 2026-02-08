#include "ScalarConverter.hpp"

void ScalarConverter::printChar(const double& value, const bool& is_pseudo) {
    // Print char 
    std::cout << "char: ";
    if (is_pseudo || value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";
};

void ScalarConverter::printInt(const double& value, const bool& is_pseudo) {
    // Print int
    std::cout << "int: ";
    if (is_pseudo || value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";
};

void ScalarConverter::printFloat(const double& value, const bool& is_pseudo) {
    // Print float
    std::cout << "float: ";
    if (is_pseudo)
    {
        if (std::isnan(value))
            std::cout << "nanf\n";
        else if (value < 0)
            std::cout << "-inff\n";
        else
            std::cout << "+inff\n";
    }
    else
    {
        float f = static_cast<float>(value);
        std::cout << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f\n";
    }
};

void ScalarConverter::printDouble(const double& value, const bool& is_pseudo) {
    // Print doubl
    std::cout << "double: ";
    if (is_pseudo)
    {
        if (std::isnan(value))
            std::cout << "nan\n";
        else if (value < 0)
            std::cout << "-inf\n";
        else
            std::cout << "+inf\n";
    }
    else
    {
        std::cout << value;
        if (value == static_cast<int>(value))
            std::cout << ".0";
        std::cout << "\n";
    }
};