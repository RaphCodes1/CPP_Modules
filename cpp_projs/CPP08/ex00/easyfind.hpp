#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class ValueNotFoundException: public std::exception{
    public:
        const char* what() const throw(){
            return "Value not found!";
        };
};

template<typename T>
typename T::iterator easyfind(T& container, int num){
    
    typename T::iterator it = std::find(container.begin(),container.end(),num);
    
    if(it != container.end())
        return it;
    else
        throw ValueNotFoundException();
}