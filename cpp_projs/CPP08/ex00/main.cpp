#include "easyfind.hpp"

int main(){
    std::vector<int> numbers;

    for(size_t i = 0; i < 10; i++)
        numbers.push_back(i);
    
    for(size_t i = 0;i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    
    try{
        int result = *easyfind(numbers,4);
        std::cout << std::endl;
        std::cout << "found value: " << result << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        double result = *easyfind(numbers,42);
        std::cout << std::endl;
        std::cout << "found value: " << result << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}