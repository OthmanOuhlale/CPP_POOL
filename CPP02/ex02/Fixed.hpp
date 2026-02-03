#ifndef FIXED_HPP
# define  FIXED_HPP

#include <iostream>
#include <cmath>
#include <ostream>

class Fixed
{
  private:
    int fixed;
    static const int fractionalBits;
  public:
    Fixed( void );
    Fixed(const int int_value);
    Fixed(const float float_value);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int   getRawBits( void ) const;
    void  setRawbits(int const raw);
    float toFloat( void ) const;
    int   toInt( void ) const;

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed &operator++();
    Fixed &operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    static Fixed& min(Fixed& obj1, Fixed& obj2);
    static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
    static Fixed& max(Fixed& obj1, Fixed& obj2);
    static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif
