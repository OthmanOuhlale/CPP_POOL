#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "----- Default constructor -----" << std::endl;
    Array<int> a;
    std::cout << "size: " << a.size() << std::endl;

    std::cout << "\n----- Constructor with size -----" << std::endl;
    Array<int> b(5);
    std::cout << "size: " << b.size() << std::endl;

    for (int i = 0; i < b.size(); i++)
        b[i] = i * 10;

    for (int i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "\n----- Copy constructor -----" << std::endl;
    Array<int> c(b);

    for (int i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    std::cout << "\n----- Assignment operator -----" << std::endl;
    Array<int> d;
    d = b;

    for (int i = 0; i < d.size(); i++)
        std::cout << d[i] << " ";
    std::cout << std::endl;

    std::cout << "\n----- Subscript operator test -----" << std::endl;
    b[0] = 999;

    std::cout << "b[0] = " << b[0] << std::endl;

    std::cout << "\n----- Exception test -----" << std::endl;

    try
    {
        std::cout << b[100] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

