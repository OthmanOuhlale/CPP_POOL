#include "PmergeMe.hpp"

int main (int argc, char **argv) {
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe <positive integer sequence>"
                << std::endl;
        return (1);
    }

    PmergeMe pm;

    pm.inputParsing(argv);

    std::vector<int> vect = pm.getVect();

    for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
    {
        std::cout << *it << std::endl;
    }    

    return (0);
}