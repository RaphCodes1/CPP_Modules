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

int Span::shortestSpan(){
    std::vector<int> sorted = _numbers;

    std::sort(sorted.begin(), sorted.end());

    int shortestNum = std::numeric_limits<int>::max();

    std::cout << "shortest num for now: " << shortestNum << std::endl;
    for(size_t i = 0; i < sorted.size() - 1; i++){
        int difference = sorted[i + 1] - sorted[i];
        shortestNum = difference;
    }

    return shortestNum;
}