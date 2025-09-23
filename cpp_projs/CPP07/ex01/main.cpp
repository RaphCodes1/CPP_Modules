#include "iter.hpp"

template<typename T>
void increment(T& a){
    a++;
}

template<typename T>
void toPrint(T &a){
    std::cout << a << " ";
}

int main(){
    char charArr[] = {'a','b','c','d','e'};
    int intArr[] = {1,2,3,4,5};

    const char charConst[] = {'a','b','c','d','e'};

    ::iter(charConst, 5, toPrint<const char>);
    std::cout << std::endl;
    ::iter(charArr,5, toPrint<char>);
    std::cout << std::endl;
    ::iter(intArr, 5, toPrint<int>);
    std::cout << std::endl;

    ::iter(intArr, 5, increment<int>);
    std::cout << std::endl;
    ::iter(intArr, 5, toPrint<int>);
    std::cout << std::endl;
    ::iter(charArr, 5, increment<char>);
    std::cout << std::endl;
    ::iter(charArr, 5, toPrint<char>);
    std::cout << std::endl;
}