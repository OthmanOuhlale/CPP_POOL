#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    (void)other;
    return (*this);
};

ScalarConverter::~ScalarConverter() {};

void ScalarConverter::convert(const std::string& literal)
{
    double  value;
    bool    is_pseudo = isPseudo(literal);

    // Convert to double
    if (is_pseudo)
    {
        if (literal == "nan" || literal == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (literal[0] == '-')
            value = -std::numeric_limits<double>::infinity();
        else
            value = std::numeric_limits<double>::infinity();
    }
    else if (isInt(literal))
        value = std::strtod(literal.c_str(), NULL);
    else if (isFloat(literal))
        value = std::strtod(literal.c_str(), NULL);
    else if (isDouble(literal))
        value = std::strtod(literal.c_str(), NULL);
    else
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    printChar(value, is_pseudo);
    printInt(value, is_pseudo);
    printFloat(value, is_pseudo);
    printDouble(value, is_pseudo);
};
