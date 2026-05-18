#include "PmergeMe.hpp"

static time_t now_us()
{
    timeval tv;
    gettimeofday(&tv, 0);
    return tv.tv_sec * 1000000LL + tv.tv_usec;
}

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

        long long startVec = now_us();
        pm.fordJohnsonSortVector(vec);
        long long endVec = now_us();

        // DEQUE
        std::deque<Element> deq;

        for (size_t i = 0; i < inputDeque.size(); i++)
        {
            Element e;
            e.value = inputDeque[i];
            deq.push_back(e);
        }

        long long startDeque = now_us();
        pm.fordJohnsonSortDeque(deq);
        long long endDeque = now_us();

        // AFTER
        std::cout << "After:  ";
        printVectorElements(vec);

        // TIMES
        std::cout << "Time to process a range of "
                  << inputVec.size()
                  << " elements with std::vector : "
                  << endVec - startVec
                  << " us"
                  << std::endl;

        std::cout << "Time to process a range of "
                  << inputDeque.size()
                  << " elements with std::deque  : "
                  << endDeque - startDeque
                  << " us"
                  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}