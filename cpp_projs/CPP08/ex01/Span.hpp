#pragma once

#include <algorithm>
#include <iostream>
#include <span>
#include <vector>

class Span{
    private:
        std::vector<int> _numbers;
        unsigned int _size;
    public:
        Span();
        Span(unsigned int size);
        ~Span();
        Span(const Span& src);
        Span &operator=(const Span& src);
        void addNumber(int num);
        void shortestSpan();
        void longestSpan();

        void printVal();
};

