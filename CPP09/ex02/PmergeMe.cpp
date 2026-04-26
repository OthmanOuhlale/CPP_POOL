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
            return (0);
    }
    return (1);
}

void PmergeMe::inputParsing(char** input) {
    int i = 1;
    while (input[i])
    {
        std::string arg = input[i];
        std::istringstream ss(arg);
        std::string token;
        while (ss >> token)
        {
            if (!isNumber(token))
                throw std::runtime_error("Error");
            int nbr = std::atoi(token.c_str());
            if (nbr < 0)
                throw std::runtime_error("Error");
            std::vector<int>::iterator it = std::find(_vect.begin(), _vect.end(), nbr);
            if (it != _vect.end())
                throw std::runtime_error("Error");
            _vect.push_back(nbr);
            _dec.push_back(nbr);
        }
        i++;
    }
    if (_vect.size() == 0 && _dec.size() == 0)
        throw std::runtime_error("Error");
}

void PmergeMe::fordJhonsonSort(std::vector<Element>& vec)
{
    if (vec.size() <= 1)
        return;

    std::vector<Element> main;
    std::vector<Element> pend;

    //Pairing
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        Element a = vec[i];
        Element b = vec[i + 1];

        if (a.value > b.value)
            std::swap(a, b);

        main.push_back(b);
        pend.push_back(a);
    }

    Element leftover;
    bool hasLeftover = false;

    if (vec.size() % 2 != 0)
    {
        leftover = vec.back();
        hasLeftover = true;
    }

    // sort big elements
    fordJhonsonSort(main);

    // Insert pend into sorted main
    for (size_t i = 0; i < pend.size(); i++)
    {
        size_t bound = i + 1;
        if (bound > main.size())
            bound = main.size();

        std::vector<Element>::iterator pos =
            std::lower_bound(main.begin(), main.begin() + bound, pend[i]);

        main.insert(pos, pend[i]);
    }

    // Insert leftover
    if (hasLeftover)
    {
        std::vector<Element>::iterator pos =
            std::lower_bound(main.begin(), main.end(), leftover);

        main.insert(pos, leftover);
    }

    // Copy result
    vec = main;
}
