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
        else if (!std::isdigit(literal[i]))
            return (false);
        i++;
    }
    if (dot_count != 1)
        return (false);
    if (literal[0] == '.' || literal[literal.length() - 2] == '.')
        return (false);

    return (true);
};

bool ScalarConverter::isDouble(const std::string& literal) {
    size_t  i = 0;
    size_t  dot_count = 0;

    if (literal.length() < 3)
        return (false);
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    while (i < literal.length() - 1)
    {
        if (literal[i] == '.')
            dot_count++;
        if (!std::isdigit(literal[i]))
            return (false);
        i++;
    }
    if (dot_count != 1)
        return (false);
    if (literal[0] == '.' || literal[literal.length() - 1] == '.')
        return (false);

    return (true);
}

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
    else if (isChar(literal))
        value = static_cast<double>(literal[0]);
    else if (isInt(literal))
        value = static_cast<double>(std::atoi(literal.c_str()));
    else if (isFloat(literal))
        value = static_cast<double>(std::atof(literal.c_str()));
    else if (isDouble(literal))
        value = std::atof(literal.c_str());
    else
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    // Print char 
    std::cout << "char: ";
    if (is_pseudo || value < 0 || value > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(value) << "'\n";

    // Print int  
    std::cout << "int: ";
    if (is_pseudo || value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(value) << "\n";

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
