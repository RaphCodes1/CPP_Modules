#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array{
    private:
        T* _elements;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int size);
        ~Array();
        Array(const Array &src);
        Array &operator=(const Array &src);
        T& operator[](unsigned int index);
        int size();
};

#include "Array.tpp"

#endif