#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    private:
        int _size;
        T*  _data;
    public:
        Array();
        Array(int n);
        Array(const Array& other);
        Array&  operator=(const Array& other);
        T&      operator[](int index);
        int     size() const;
};

#endif
