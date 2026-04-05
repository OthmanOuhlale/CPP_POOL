#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->_maxSize = other._maxSize;
        this->_data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_data.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    
    _data.push_back(number);
}

int Span::shortestSpan() {
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements");
    
    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());
    int minSpan = tmp[1] - tmp[0];
    for (size_t i = 0; i < tmp.size() - 1; i++)
    {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return (minSpan);
}

int Span::longestSpan() {
    if (_data.size() < 2)
        throw std::runtime_error("Elements not enough");

    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());

    int maxSpan = max - min;

    return (maxSpan);
}
