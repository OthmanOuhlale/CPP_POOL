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

bool ScalarConverter::isPseudo(const std::string& literal)
{
    if (literal == "nan" || literal == "nanf")
        return true;
    if (literal == "+inf" || literal == "-inf" || literal == "inf")
        return true;
    if (literal == "+inff" || literal == "-inff" || literal == "inff")
        return true;
    return false;
};

bool ScalarConverter::isChar(const std::string& literal) {
    if (literal.length() != 1)
        return (false);
    else if (std::isdigit(literal[0]))
        return (false);
    else if (!std::isprint(literal[0]))
        return (false);
    return (true);
};

bool ScalarConverter::isInt(const std::string& literal) {
    size_t i = 0;

    if (literal.empty())
        return (false);
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i == literal.length())
        return (false);
    while (i < literal.length() - 1)
    {
        if (!std::isdigit(literal[i]))
            return (false);
        i++;
    }
    return (true);
};

bool ScalarConverter::isFloat(const std::string& literal) {
    size_t i = 0;
    size_t dot_count = 0;

    if (literal.length() < 4)
        return (false);
    if (literal[literal.length() - 1] != 'f')
        return (false);
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    while (i < literal.length() - 1)
    {
        if (literal[i] == '.')
            dot_count++;
        if (!std::isdigit(literal[i]))
            return (false);
    }
    if (dot_count != 1)
        return (false);
    if (literal[0] == '.' || literal[literal.length() - 2] == '.')
        return (0);

    return (true);
};

void ScalarConverter::convert(const std::string& input) {

};

