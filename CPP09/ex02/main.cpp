#include "PmergeMe.hpp"

void printVectorOfElements(std::vector<Element> vect) {
    for (size_t i = 0; i < vect.size(); i++)
        std::cout << vect[i].value << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
        return 1;
    }

    PmergeMe pm;

    try
    {
        pm.inputParsing(argv);

        std::vector<int> input = pm.getVect();
        std::vector<Element> vec;

        for (size_t i = 0; i < input.size(); i++)
        {
            Element e;
            e.value = input[i];
            vec.push_back(e);
        }

        std::cout << "Before: ";
        printVectorOfElements(vec);
        std::cout << std::endl;

        pm.fordJhonsonSort(vec);

        std::cout << "After: ";
        printVectorOfElements(vec);
        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
