#ifndef FIXED_HPP
# define  FIXED_HPP

#include <iostream>

class Fixed
{
  private:
    int fixed;
    static const int fractionalBits;
  public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawbits(int const raw);
};

#endif
