#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <exception>
#include <cstdlib>
#include <utility>

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

        void    fordJhonsonSort(std::vector<int>& vec);
};

#endif
