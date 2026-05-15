#include "RPN.hpp"

RPN::RPN() {};

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        this->_data = other._data;
    return *this;
}

RPN::~RPN() {};

int RPN::evaluate(const std::string& input) {
    std::istringstream ss(input);
    std::string        token;

    while ( ss >> token)
    {
        if (token.size() == 1 && isdigit(token[0]))
        {
            int value = token[0] - '0';
            _data.push(value);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_data.size() < 2)
                throw std::runtime_error("Error");
            int b = _data.top();
            _data.pop();
            int a = _data.top();
            _data.pop();
            if (token == "+")
                _data.push(a + b);
            if (token == "-")
                _data.push(a - b);
            if (token == "*")
                _data.push(a * b);
            if (token == "/")
            {
                if (b == 0)
                    throw std::runtime_error("Error: division by zero");
                _data.push(a / b);
            }
        }
        else
            throw std::runtime_error("Error");
    }
    if (_data.size() != 1)
        throw std::runtime_error("Error");

    return (_data.top());
}
