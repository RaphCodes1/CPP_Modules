#include "Span.hpp"

Span::Span():_numbers(0), _size(0){};

Span::~Span(){};

Span::Span(unsigned int size): _size(size){
    this-> _numbers.reserve(this->_size);
};

Span::Span(const Span& src):_numbers(src._numbers), _size(src._size){};

Span &Span::operator=(const Span& src){
    if(this != &src)
    {
        this->_numbers = src._numbers;
        this->_size = src._size;
    }
    return *this;
}

void Span::addNumber(int num){
    if(_numbers.size() == _size)
        throw SpanErrorException();
    this->_numbers.push_back(num);
}


int Span::shortestSpan(){
    std::vector<int> sorted = _numbers;

    std::sort(sorted.begin(), sorted.end());

    int shortestNum = std::numeric_limits<int>::max();
    for(size_t i = 0; i < sorted.size() - 1; i++){
        int difference = sorted[i + 1] - sorted[i];
        if(difference < shortestNum)
            shortestNum = difference;
    }
    return shortestNum;
}

int Span::longestSpan(){
    std::vector<int> sorted = _numbers;

    std::sort(sorted.begin(), sorted.end());

    return sorted.back() - sorted.front();
}

int Span::getSize(){
    return _size;
}