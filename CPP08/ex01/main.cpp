#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    // Normal test :
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // Test exception of not enough elements
    Span s2(1);
    s2.addNumber(0);
    try
    {
        std::cout << "Shortest: " << s2.shortestSpan() << std::endl;
        std::cout << "Longest: " << s2.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Large test
    std::srand(std::time(NULL));
    Span s3(10000);
    std::vector<int> v;
    for (size_t i = 0; i < 10000; i++)
    {
        v.push_back(std::rand());
    }
    s3.addRange(v.begin(), v.end());
    std::cout << "Shortest: " << s3.shortestSpan() << std::endl;
    std::cout << "Longest: " << s3.longestSpan() << std::endl;

    return 0;
}