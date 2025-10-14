#include "Span.hpp"
int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    srand(time(0));
    try{
        Span sp = Span(10000);
        for(int i = 0; i < sp.getSize();i++)
        {
            sp.addNumber(i);
        }
        std::cout << "Random shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Random longest: " << sp.longestSpan() << std::endl;
    } catch(std::exception &e){
        std::cout << "exception found: " << e.what() << std::endl;
    }
    return 0;
}