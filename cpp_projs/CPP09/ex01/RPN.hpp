#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>

class RPN{
    private:
        std::stack<long double> queue;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& src);
        RPN &operator=(const RPN& src);

        bool RPNprocess(std::string s);
};