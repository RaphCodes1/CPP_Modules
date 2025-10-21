#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
class RPN{
    private:
        std::stack<long long> queue;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& src);
        RPN &operator=(const RPN& src);

        bool RPNprocess(std::string s);
};