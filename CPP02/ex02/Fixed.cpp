#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixed(0) {};

Fixed::Fixed(const int int_value) {
    fixed = int_value * (1 << fractionalBits);
};

Fixed::Fixed(const float float_value) {
    fixed = round(float_value * (1 << fractionalBits));
};

Fixed::Fixed(const Fixed& other) {
    *this = other;
};

Fixed &Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->fixed = other.fixed;
    return (*this);
};

Fixed::~Fixed( void ) {};

int Fixed::getRawBits( void ) const {
    return (fixed);
};

void Fixed::setRawbits(int const raw) {
    fixed = raw;
};

int Fixed::toInt( void ) const {
    return (fixed >> fractionalBits);
};

float Fixed::toFloat( void ) const {
  return ((float)fixed / (float)(1 << fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix) {
  os << fix.toFloat();
  return os;
}

bool Fixed::operator>(const Fixed& other) const {
    if (this->fixed > other.fixed)
        return (true);
    return (false);
};

bool Fixed::operator<(const Fixed& other) const {
    if (this->fixed < other.fixed)
        return (true);
    return (false);
};

bool Fixed::operator>=(const Fixed& other) const {
    if (this->fixed >= other.fixed)
        return (true);
    return (false);
};

bool Fixed::operator<=(const Fixed& other) const {
    if (this->fixed <= other.fixed)
        return (true);
    return (false);
};

bool Fixed::operator==(const Fixed& other) const {
    if (this->fixed == other.fixed)
        return (true);
    return (false);
};

bool Fixed::operator!=(const Fixed& other) const {
    if (this->fixed != other.fixed)
        return (true);
    return (false);
};

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed res;
    res.setRawbits(this->fixed + other.fixed);
    return (res);
};

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed res;
    res.setRawbits(this->fixed - other.fixed);
    return (res);
};

Fixed Fixed::operator*(const Fixed &other) const {
    return (Fixed(this->toFloat() * other.toFloat()));
};

Fixed Fixed::operator/(const Fixed &other) const {
    return (Fixed(this->toFloat() / other.toFloat()));
};

Fixed& Fixed::operator++() {
    this->fixed++;
    return (*this);
}

Fixed& Fixed::operator--() {
    this->fixed--;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->fixed++;
    return (temp);
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->fixed--;
    return (temp);
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2) {
    if (obj1 < obj2)
    {
        return (obj1);
    }
    return (obj2);
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2) {
    if (obj1 < obj2)
    {
        return (obj1);
    }
    return (obj2);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2) {
    if (obj1 > obj2)
    {
        return (obj1);
    }
    return (obj2);
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2) {
    if (obj1 > obj2)
    {
        return (obj1);
    }
    return (obj2);
}
