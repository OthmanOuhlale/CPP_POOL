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

std::vector<size_t> PmergeMe::jacobsthalOrderVector(size_t n)
{
    std::vector<size_t> order;
    if (n == 0) return order;

    order.push_back(0);

    size_t j_prev = 1;
    size_t j_curr = 3;

    while (j_prev < n)
    {
        size_t end;
        if (j_curr < n)
            end = j_curr;
        else
            end = n;

        for (size_t i = end; i > j_prev; i--)
            order.push_back(i - 1);

        size_t j_next = j_curr + 2 * j_prev;
        j_prev = j_curr;
        j_curr = j_next;
    }
    return order;
}

void PmergeMe::fordJohnsonSortVector(std::vector<Element>& vec)
{
    if (vec.size() <= 1)
        return;

    std::vector<Element> mainChain;
    std::vector<Element> pend;
    std::vector<Element> pend_restord;

    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        Element a = vec[i];
        Element b = vec[i + 1];

        if (a.value > b.value)
            std::swap(a, b);

        b.addItem(mainChain.size());
        mainChain.push_back(b);
        pend.push_back(a);
    }

    Element leftover;
    bool hasLeftover = false;
    if (vec.size() % 2 != 0)
    {
        leftover = vec.back();
        hasLeftover = true;
    }

    fordJohnsonSortVector(mainChain);

    for (size_t i = 0; i < mainChain.size(); i++)
    {
        int idx = mainChain[i].getItem();
        pend_restord.push_back(pend[idx]);
    }

    std::vector<size_t> pos(pend_restord.size());
    for (size_t j = 0; j < pos.size(); j++)
        pos[j] = j;

    std::vector<size_t> order = jacobsthalOrderVector(pend_restord.size());

    for (size_t k = 0; k < order.size(); k++)
    {
        size_t j = order[k];

        std::vector<Element>::iterator insertPos =
            std::lower_bound(mainChain.begin(), mainChain.begin() + pos[j], pend_restord[j]);

        size_t insertIdx = (size_t)(insertPos - mainChain.begin());
        mainChain.insert(insertPos, pend_restord[j]);

        for (size_t m = 0; m < pos.size(); m++)
            if (pos[m] >= insertIdx)
                pos[m]++;
    }

    if (hasLeftover)
    {
        std::vector<Element>::iterator insertPos =
            std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(insertPos, leftover);
    }

    vec = mainChain;
}

std::deque<size_t> PmergeMe::jacobsthalOrderDeque(size_t n)
{
    std::deque<size_t> order;

    if (n == 0)
        return order;

    order.push_back(0);

    size_t j_prev = 1;
    size_t j_curr = 3;

    while (j_prev < n)
    {
        size_t end;

        if (j_curr < n)
            end = j_curr;
        else
            end = n;

        for (size_t i = end; i > j_prev; i--)
            order.push_back(i - 1);

        size_t j_next = j_curr + 2 * j_prev;
        j_prev = j_curr;
        j_curr = j_next;
    }

    return order;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<Element>& vec)
{
    if (vec.size() <= 1)
        return;

    std::deque<Element> mainChain;
    std::deque<Element> pend;
    std::deque<Element> pend_restord;

    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        Element a = vec[i];
        Element b = vec[i + 1];

        if (a.value > b.value)
            std::swap(a, b);

        b.addItem(mainChain.size());

        mainChain.push_back(b);
        pend.push_back(a);
    }

    Element leftover;
    bool hasLeftover = false;

    if (vec.size() % 2 != 0)
    {
        leftover = vec.back();
        hasLeftover = true;
    }

    fordJohnsonSortDeque(mainChain);

    for (size_t i = 0; i < mainChain.size(); i++)
    {
        int idx = mainChain[i].getItem();
        pend_restord.push_back(pend[idx]);
    }

    std::deque<size_t> pos(pend_restord.size());

    for (size_t j = 0; j < pos.size(); j++)
        pos[j] = j;

    std::deque<size_t> order = jacobsthalOrderDeque(pend_restord.size());

    for (size_t k = 0; k < order.size(); k++)
    {
        size_t j = order[k];

        std::deque<Element>::iterator insertPos =
            std::lower_bound(
                mainChain.begin(),
                mainChain.begin() + pos[j],
                pend_restord[j]
            );

        size_t insertIdx = insertPos - mainChain.begin();

        mainChain.insert(insertPos, pend_restord[j]);

        for (size_t m = 0; m < pos.size(); m++)
        {
            if (pos[m] >= insertIdx)
                pos[m]++;
        }
    }

    if (hasLeftover)
    {
        std::deque<Element>::iterator insertPos =
            std::lower_bound(
                mainChain.begin(),
                mainChain.end(),
                leftover
            );

        mainChain.insert(insertPos, leftover);
    }

    vec = mainChain;
}
