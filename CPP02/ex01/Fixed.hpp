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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif
