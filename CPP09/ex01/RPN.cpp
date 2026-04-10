#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
    {
        this->_data = other._data;
    }
    return *this;
}

RPN::~RPN() {};

int RPN::evaluate(const std::string& input) {
    std::istringstream ss;
    std::string        token;

    while ( ss >> token)
    {
        if (token == "+" || token == "-"
            | token == "*" | token == "/")
        {
            std::cout << "operator" << std::endl;
        } else {
            int value;
            ss >> value;
            _data.push(value);
        }
        
    }
    
    return (0);
}