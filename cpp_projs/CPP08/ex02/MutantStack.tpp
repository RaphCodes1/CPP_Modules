#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& src){}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& src){};

template<typename T>
void MutantStack<T>::push(T val){
    stack.push_back(val);
}

template<typename T>
void MutantStack<T>::pop(){
    stack.pop_back();
}

template<typename T>
std::vector<T>* MutantStack<T>::top(){
    return &stack[0];
}
