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

        clock_t startVec = clock();
        pm.fordJohnsonSort(vec);
        clock_t endVec = clock();
        double timeVec = (double)(endVec - startVec);

        std::cout << "After: ";
        printVectorOfElements(vec);
        std::cout << std::endl;
        std::cout << "Time to process a range of " << vec.size()
        << " elements with std::vector : " << timeVec << std::endl;
        std::cout << "Comparisons: " << Element::comparisons << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
