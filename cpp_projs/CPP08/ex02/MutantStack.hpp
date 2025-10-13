#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

// template<typename T>
// typename T MutantStack()

template<typename T>
class MutantStack{
    private:
        std::vector<T> stack;
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &src);
        MutantStack &operator=(const MutantStack &src);
    public:
        void push(T val);
        void pop();
        std::vector<T>* top();
        void empty();
        void size();
};

#include "MutantStack.tpp"
