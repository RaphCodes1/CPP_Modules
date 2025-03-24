# include "Header.hpp"

int main()
{
    std::string bruh = " test one two ddddddd  ";
    std::string test = "";
    int start = 0;
    
    while(start < bruh.size() && (std::isspace(bruh[start])))
    {
        std::cout << bruh[start];
        start++;
    }

    std::cout << std::endl;
    
    int end = bruh.size();
    while(end > start && (std::isspace(bruh[start - 1])))
    {
        std::cout << bruh[end];
        end--;
    }

    std::cout << std::endl;
    
    bruh.substr(start, end - start);
    std::cout << start << std::endl;
    std::cout << end << std::endl;
    std::cout << bruh << std::endl;
    
}