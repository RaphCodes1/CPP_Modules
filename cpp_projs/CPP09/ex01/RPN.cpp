#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& src){
    *this = src;
}

RPN &RPN::operator=(const RPN& src){
    if(this != &src)
    {
        *this = src;
    }
    return *this;
}

void RPN::RPNprocess(std::string s){
    
    std::cout << s << std::endl;

    int num1;
    int num2;
    char operation;

    // for(size_t i = 0; i < s.length())
    

}

