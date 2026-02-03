#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << "\n---- Increment Tests ----" << std::endl;

    std::cout << "a      = " << a << std::endl;
    std::cout << "++a    = " << ++a << std::endl;
    std::cout << "a      = " << a << std::endl;
    std::cout << "a++    = " << a++ << std::endl;
    std::cout << "a      = " << a << std::endl;

    std::cout << "\n---- Arithmetic Tests ----" << std::endl;

    Fixed x(10);
    Fixed y(3);

    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;

    std::cout << "\n---- Comparison Tests ----" << std::endl;

    std::cout << "(x > y)  = " << (x > y) << std::endl;
    std::cout << "(x < y)  = " << (x < y) << std::endl;
    std::cout << "(x >= y) = " << (x >= y) << std::endl;
    std::cout << "(x <= y) = " << (x <= y) << std::endl;
    std::cout << "(x == y) = " << (x == y) << std::endl;
    std::cout << "(x != y) = " << (x != y) << std::endl;

    std::cout << "\n---- Min/Max Tests ----" << std::endl;

    Fixed a1(5.5f);
    Fixed a2(10.1f);

    std::cout << "min(a1, a2) = " << Fixed::min(a1, a2) << std::endl;
    std::cout << "max(a1, a2) = " << Fixed::max(a1, a2) << std::endl;

    Fixed const c1(42.42f);
    Fixed const c2(21.21f);

    std::cout << "min(c1, c2) = " << Fixed::min(c1, c2) << std::endl;
    std::cout << "max(c1, c2) = " << Fixed::max(c1, c2) << std::endl;

    return (0);
}

