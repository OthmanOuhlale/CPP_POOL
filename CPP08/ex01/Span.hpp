#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int     _maxSize;
        std::vector<int> _data;
    
    public:
        Span(unsigned int n);
        Span(const Span& Other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        int shortestSpan();
        int longestSpan();

        template <typename It>
        void addRange(It begin, It end)
        {
            if (_data.size() + std::distance(begin, end) > _maxSize)
                throw std::runtime_error("Span will overflow");

            _data.insert(_data.end(), begin, end);
        }
};



#endif