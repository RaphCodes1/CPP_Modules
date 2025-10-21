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

void errorMsg()
{
    std::cerr << "Error" << std::endl;
}

bool checkValid(std::string &s)
{
    for(size_t i = 0; i < s.length(); i++)
    {
        if(s[i] >='0' && s[i] <= '9')
            continue;
        else if(s[i] == ' ')
            continue;
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            continue;
        else
            return false;
    }
    return true;
}

bool RPN::RPNprocess(std::string s){
    
    std::cout << s << std::endl;
    
    if(!checkValid(s)){    
        errorMsg();
        return false; }
    char operation = '0';
    int numOne;
    int numTwo;
    int res;

    for(size_t i = 0; i < s.length(); i++)
    {   
        if(queue.empty())
        {
            if(s[i] >= '0' && s[i] <= '9')
                this->queue.push(s[i]);
            else if(s[i] == ' ')
                continue;
            else if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
                operation = s[i];
            // if(operation != '0' && queue.size() == 2)
            // {
            //     w
            // }
        }
    }
    
    
        
    
    return true;
}

