#include "iter.hpp"

template <typename T>
void printElement(T const &x) {
    std::cout << x << std::endl;
}

int main () {
    char charArray[] = {'a', 'b', 'c'};
    std::cout << "Print Char: " << std::endl;
    iter(charArray, 3, &printElement);

    int  intArray[] = {1, 2, 3};
    std::cout << "Print Integers: " << std::endl;
    iter(intArray, 3, &printElement);

    double doubleArray[] = {1.1, 1.2, 1.3};
    std::cout << "Print Doubles: " << std::endl;
    iter(doubleArray, 3, &printElement);

    return (0);    
}
