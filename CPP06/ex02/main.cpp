#include "functions.hpp"
#include <ctime>

int main( void ) {
    std::srand(std::time(NULL));

    Base* obj = generate();

    identify(obj);
    identify(*obj);

    delete obj;
    return (0);
};
