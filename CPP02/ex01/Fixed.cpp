#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixed(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int int_value) {
    std::cout << "Int constructor called" << std::endl;
    fixed = int_value * (1 << fractionalBits);
};

Fixed::Fixed(const float float_value) {
    std::cout << "Float constructor called" << std::endl;
    fixed = round(float_value * (1 << fractionalBits));
};

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
};

Fixed &Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixed = other.fixed;
    return (*this);
};

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called\n";
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
