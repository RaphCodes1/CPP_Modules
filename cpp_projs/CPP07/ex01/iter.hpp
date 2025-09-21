#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template<typename T,size_t N>
void iter(T (&arr)[N], size_t const length, void (*func)(T&))
{
    for(size_t i = 0; i < length; i++)
    {
        func(arr[i]);
    }
}

template<typename T>
void toPrint(const T &a)
{
    std::cout << a << std::endl;
}

template<typename T>
void toPrint(T &a)
{
    std::cout << a << ",";
}

template<typename T>
void toShift(T& a){
    a++;
}
#endif