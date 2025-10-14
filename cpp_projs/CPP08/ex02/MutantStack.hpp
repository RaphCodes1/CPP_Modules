#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack<T> &src);
        MutantStack &operator=(const MutantStack<T> &src);
        typedef typename std::deque<T>::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"
