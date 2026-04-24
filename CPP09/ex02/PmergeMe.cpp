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

// void PmergeMe::divideToPairs() {
//     size_t i = 0;
//     while (i + 1 < _vect.size())
//     {
//         int a = _vect[i];
//         int b = _vect[i + 1];
//         if (a > b)
//             std::swap(a, b);

//         _pairs.push_back(std::make_pair(a, b));

//         i += 2;
//     }
//     if (_vect.size() % 2 != 0)
//     {
//         _hasLeftover = true;
//         _leftover = _vect.back();
//     }
// }

// void PmergeMe::buildMainAndPend() {
//     if (_pairs.empty())
//         return;
//     for (size_t i = 0; i < _pairs.size(); i++)
//         _main.push_back(_pairs[i].second);
//     for (size_t i = 0; i < _pairs.size(); i++)
//         _pend.push_back(_pairs[i].first);
//     if (_hasLeftover)
//         _pend.push_back(_leftover);
// }

// void PmergeMe::fordJhonsonSort(std::vector<int>& vec) {
//     std::vector< std::pair<int, int> >  pairs;
//     std::vector<int>                    bigs;
//     std::vector<int>                    smalls;

//     // create sorted pairs:
//     for (size_t i = 0; i + 1 < vec.size(); i += 2)
//     {
//         int a = vec[i];
//         int b = vec[i + 1];
//         if (a > b)
//             std::swap(a, b);

//         pairs.push_back(std::make_pair(a, b));
//     }

//     // fill bigs and smalls:
//     if (vec.size() <= 1)
//         return;
//     for (size_t i = 0; i < pairs.size(); i++)
//         smalls.push_back(pairs[i].first);
//     for (size_t i = 0; i < pairs.size(); i++)
//         bigs.push_back(pairs[i].second);
//     if (vec.size() % 2 != 0)
//         smalls.push_back(vec.back());

//     fordJhonsonSort(bigs);
// }

void PmergeMe::fordJhonsonSort(std::vector<int>& vec) {
    std::vector<int>                    main;
    std::vector<int>                    pend;

    if (vec.size() <= 1)
        return;
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i + 1];
        if (a > b)
            std::swap(a, b);

        pend.push_back(a);
        main.push_back(b);
    }
    if (vec.size() % 2 != 0)
        pend.push_back(vec.back());

    fordJhonsonSort(main);

    // create a maped vector of smalls to optimize the insertion

    // insert smalls using binary insertion to the main chain
    for (size_t i = 0; i < pend.size(); i++)
    {
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[i]);
        main.insert(pos, pend[i]);
    }
    vec = main;
}
