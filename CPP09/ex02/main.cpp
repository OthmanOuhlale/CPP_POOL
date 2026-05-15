#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

void printVector(const std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void printVectorElements(const std::vector<Element>& vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i].value << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
        return (1);
    }

    PmergeMe pm;

    try
    {
        pm.inputParsing(argv);

        std::vector<int> inputVec = pm.getVect();
        std::deque<int> inputDeque = pm.getDec();

        // BEFORE
        std::cout << "Before: ";
        printVector(inputVec);

        // VECTOR
        std::vector<Element> vec;

        for (size_t i = 0; i < inputVec.size(); i++)
        {
            Element e;
            e.value = inputVec[i];
            vec.push_back(e);
        }

        Element::comparisons = 0;

        clock_t startVec = clock();
        pm.fordJohnsonSortVector(vec);
        clock_t endVec = clock();

        double timeVec =
            ((double)(endVec - startVec) / CLOCKS_PER_SEC) * 1000000;

        // DEQUE
        std::deque<Element> deq;

        for (size_t i = 0; i < inputDeque.size(); i++)
        {
            Element e;
            e.value = inputDeque[i];
            deq.push_back(e);
        }

        clock_t startDeque = clock();
        pm.fordJohnsonSortDeque(deq);
        clock_t endDeque = clock();

        double timeDeque =
            ((double)(endDeque - startDeque) / CLOCKS_PER_SEC) * 1000000;

        // AFTER
        std::cout << "After:  ";
        printVectorElements(vec);

        // TIMES
        std::cout << std::fixed << std::setprecision(5);

        std::cout << "Time to process a range of "
                  << inputVec.size()
                  << " elements with std::vector : "
                  << timeVec
                  << " us"
                  << std::endl;

        std::cout << "Time to process a range of "
                  << inputDeque.size()
                  << " elements with std::deque  : "
                  << timeDeque
                  << " us"
                  << std::endl;

        // COMPARISONS
        std::cout << "Comparisons: "
                  << Element::comparisons
                  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}