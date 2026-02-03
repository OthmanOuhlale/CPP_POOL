#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fixed(0) {
    std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->fixed = other.getRawBits();
};

Fixed &Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixed = other.getRawBits();
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
