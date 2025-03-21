#include <iostream>
#include <string>

int main()
{
    std::string var = "HI THIS IS BRAIN";
    std::string* stringPTR = &var;
    std::string& stringREF = *stringPTR;

    std::cout << "address of string variable: " << &var << std::endl;
    std::cout << "address held by stringPTR: " << &stringPTR << std::endl;
    std::cout << "address held by stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "value of the string variable: " << var << std::endl;
    std::cout << "value pointed to by stringPTR: " << stringPTR << std::endl;
    std::cout << "value pointed to by stringREF: " << stringREF << std::endl;


}