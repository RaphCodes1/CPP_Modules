#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
class RPN{
    private:
        std::stack<int> queue;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& src);
        RPN &operator=(const RPN& src);

        void RPNprocess(std::string s);
};