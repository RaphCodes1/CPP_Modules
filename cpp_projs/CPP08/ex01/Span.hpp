#pragma once

class Span{
    private:
    public:
        Span();
        Span(unsigned int size);
        ~Span();
        Span(Span& src);
        Span &operator=(Span& src);
        void addNumber(unsigned int num);
        void shortestSpan();
        void longestSpan();
};

