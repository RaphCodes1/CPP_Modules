#include "Span.hpp"

int main()
{
    Span a = Span(5);
    
    for(size_t i = 0; i < 5; i++)
        a.addNumber(i);
    
    a.printVal();
}