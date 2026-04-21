#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other)
    {
        this->_vect = other._vect;
        this->_dec = other._dec;
    }
    return (*this);
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::getVect() const {
    return (_vect);
}

std::deque<int> PmergeMe::getDec() const {
    return (_dec);
}

int PmergeMe::isNumber(std::string nbr) const {
    for (size_t i = 0; i < nbr.length(); i++)
    {
        if (!isdigit(nbr[i]))
            return (1);
    }
    return (0);
}

void PmergeMe::inputParsing(char** input) {
    int i = 1;
    while (input[i])
    {
        std::string arg = input[i];
        std::istringstream ss;
        std::string token;
        while (ss >> token)
        {
            if (!isNumber(token))
                throw std::runtime_error("Error");
            int nbr = std::atoi(token.c_str());
            if (nbr < 0)
                throw std::runtime_error("Error");
            _vect.push_back(nbr);
            _dec.push_back(nbr);
        }
        i++;
    }
}
