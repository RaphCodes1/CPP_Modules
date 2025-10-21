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

long long operationDone(char operation, long long one, long long two)
{
    if(operation == '+')
        return one + two;
    else if(operation == '-')
        return one - two;
    else if(operation == '/')
        return one / two;
    else if(operation == '*')
        return one * two;
    return 0;
}

bool RPN::RPNprocess(std::string s){
    
    std::cout << s << std::endl;
    if(!checkValid(s)){    
        errorMsg();
        return false; }
    char operation = '0';
    long long numOne;
    long long numTwo;
    long long res;

    for(size_t i = 0; i < s.length(); i++)
    {   
        if(s[i] == ' ')
            continue;
        else if(s[i] >= '0' && s[i] <= '9')
            this->queue.push(s[i] - '0');
        else if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
        {   
            if(queue.size() < 2){
                errorMsg();
                return false;
            }
            operation = s[i];
            if(operation != '0' && queue.size() >= 2)
            {   
                numTwo = queue.top();
                queue.pop();
                numOne = queue.top();
                queue.pop();
                std::cout  << numOne  << " " << operation << " " << numTwo << std::endl;
                res = operationDone(operation,numOne,numTwo);
                queue.push(res);
                operation = '0';
            }
        }
    }

    if(queue.size() == 1)
        std::cout << queue.top() << std::endl;
    else{
        errorMsg();
        return false;
    }
    return true;
}

