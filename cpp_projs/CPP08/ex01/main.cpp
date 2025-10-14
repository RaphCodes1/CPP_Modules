#include "Span.hpp"
int main()
{
    Span sp = Span(10);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(42);

    std::vector<int>::iterator begin = test.begin();
    std::vector<int>::iterator end = test.end();
    sp.addNumber(begin,end);
    
    return 0;
}