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
    

}

