#include "conversion.hpp"

ScalarConverter::ScalarConverter(){
    //std::cout << "ScalarConverter Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(){
    //std::cout << "ScalarConverter Destructor called" << std::endl;
}

void charCheck(const std::string &literal)
{   
    if(literal.empty())
    {
        std::cout << "int: impossible" << std::endl;
        return ;
    }

    if(literal.length() == 1 && !isdigit(literal[0]))
    {   
        if(isprint(literal[0]))
            std::cout << "char: '" << literal << "'" << std::endl;
        else
            std::cout << "char: non displayable" << std::endl; 
    }
    else
    {   
        char * endVal;
        double val = strtod(literal.c_str(), &endVal);

        if(*endVal != '\0' && (*endVal != 'f' || endVal != &literal[literal.length() -1]))
        {
            std::cout << "char: impossible" << std::endl;
            return;
        }
        else if((val < 0 || val > 127) || (isnan(val) || isinf(val)))
        {
            std::cout << "char: impossible" << std::endl;
            return;
        }
        int ascii_val = static_cast<int>(val);
        if(isprint(ascii_val)){
            std::cout << "char: '" << static_cast<char>(ascii_val) <<"'" << std::endl;
        }
        else
            std::cout << "char: non displayable" << std::endl;
    }
}

void intCheck(const std::string &literal)
{   
    if(literal.empty())
    {
        std::cout << "int: impossible" << std::endl;
        return ;
    }

    char *endVal;
    long double val = strtold(literal.c_str(),&endVal);
    
    if(&literal[0] == endVal)
        std::cout << "int: impossible" << std::endl;
    else if(*endVal != '\0' && (*endVal != 'f' || endVal != &literal[literal.length() - 1]))
        std::cout << "int: impossible" << std::endl;
    else if((isnan(val) || isinf(val)) || (val > INT_MAX || val < INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
    {
        int toInt = static_cast<int>(val);
        std::cout << "int: " << toInt << std::endl;
    }
}

void doubleCheck(const std::string &literal)
{
    if(literal.find('.') != std::string::npos)
        std::cout << "double: '" << literal << "'" << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
}

void floatCheck(const std::string &literal)
{
    if(literal.find('.') != std::string::npos && literal[literal.length() - 1] == 'f')
        std::cout << "double: '" << literal << "'" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
}
void ScalarConverter::convert(const std::string &literal){
    charCheck(literal);
    intCheck(literal);
}

