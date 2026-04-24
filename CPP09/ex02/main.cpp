#include "PmergeMe.hpp"

void printVector(std::vector<int> vect) {
    for (size_t i = 0; i < vect.size(); i++)
        std::cout << vect[i] << " ";
    std::cout << std::endl;
}

int main (int argc, char **argv) {
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe <positive integer sequence>"
                << std::endl;
        return (1);
    }

    PmergeMe pm;

    try
    {
        pm.inputParsing(argv);

        std::vector<int> vec = pm.getVect();

        std::cout << "Before: " << std::endl;
        printVector(vec);

        pm.fordJhonsonSort(vec);

        std::cout << "After: " << std::endl;
        printVector(vec);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    // std::vector<int> vect = pm.getVect();

    // for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
    // {
    //     std::cout << *it << std::endl;
    // }    
    return (0);
}
