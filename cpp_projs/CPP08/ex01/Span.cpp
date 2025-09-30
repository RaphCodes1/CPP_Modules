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
    this->_numbers.push_back(num);
}

void Span::printVal(){
    for(size_t i = 0; i < _numbers.size(); i++)
    {
        std::cout << _numbers[i] << " ";
    }
    std::cout << std::endl;
}
