#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::cout << "---- VECTOR TEST ----" << std::endl;

    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Vector error: " << e.what() << std::endl;
    }

    try
    {
        easyfind(v, 99);
    }
    catch (std::exception &e)
    {
        std::cout << "Vector error: " << e.what() << std::endl;
    }

    std::cout << "\n---- LIST TEST ----" << std::endl;

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    try
    {
        std::list<int>::iterator it = easyfind(l, 2);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "List error: " << e.what() << std::endl;
    }

    try
    {
        easyfind(l, 42);
    }
    catch (std::exception &e)
    {
        std::cout << "List error: " << e.what() << std::endl;
    }

    return 0;
}