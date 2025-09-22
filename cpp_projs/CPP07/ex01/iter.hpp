#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template<typename T,size_t N, typename F>
void iter(T (&arr)[N], size_t const length, F func)
{   
    if(length > N)
    {   
        std::cout << "invalid length" << std::endl;
        return ;
    }
    for(size_t i = 0; i < length; i++)
    {
        func(arr[i]);
    }
}

#endif