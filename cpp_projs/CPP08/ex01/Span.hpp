#pragma once

#include <algorithm>
#include <iostream>
#include <span>
#include <vector>
#include <limits>

class SpanErrorException: public std::exception{
    public:
        const char* what() const throw(){
            return "Span error";
        };
};

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
        int shortestSpan();
        int longestSpan();

        void printVal();
};

