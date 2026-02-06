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

int ScalarConverter::is_digit(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return (1);
    };
    return (0);
}

int ScalarConverter::type_detecter(const std::string& str) {
    if (str.size() == 1 && !std::isdigit(str[0]))
    {
        // char
    }
}

void ScalarConverter::convert(const std::string& input) {

}

