#include "Array.hpp"

template <typename T>
Array<T>::Array() {
    _size = 0;
    _data = 0;
}

template <typename T>
Array<T>::Array(int n) {
    _size = n;
    _data = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other) {
    _size = other._size;
    _data = new T[_size];
    for (size_t i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other)
    {
        delete _data[];
        _size = other._size;
        _data = new T[_size];
        for (size_t i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= _size)
    {
        throw std::out_of_range("index out of range");
    }
    return _data[index];
}

template <typename T>
int Array<T>::size() const {
    return _size;
}
