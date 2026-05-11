#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "Element.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <exception>
#include <cstdlib>
#include <utility>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int>                    _vect;
        std::deque<int>                     _dec;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        std::vector<int> getVect() const;
        std::deque<int> getDec() const;

        int     isNumber(std::string nbr) const;
        void    inputParsing(char** input);

        // void    divideToPairs();
        // void    buildMainAndPend();
        std::vector<size_t> jacobsthalOrder(size_t n);
        void    fordJohnsonSort(std::vector<Element>& vec);
};

#endif
