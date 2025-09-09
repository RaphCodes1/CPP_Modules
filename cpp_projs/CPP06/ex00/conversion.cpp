#include "conversion.hpp"

ScalarConverter::ScalarConverter(){
    //std::cout << "ScalarConverter Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(){
    //std::cout << "ScalarConverter Destructor called" << std::endl;
}

bool checkEmpty(const std::string &literal,std::string val)
{
    if(literal.empty())
    {
        std::cout << val << ": impossible" << std::endl;
        return true;
    }
    return false;
}

void charCheck(const std::string &literal)
{   
    if(checkEmpty(literal,"char"))
        return ;

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
        else if((val < 0 || val > 127))
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
    if(checkEmpty(literal,"int"))
        return ;

    if(literal == "nan")
    {
        std::cout << "int: impossible" << std::endl;
        return ;
    }
    char *endVal;
    long double val = strtod(literal.c_str(),&endVal);
    
    if(&literal[0] == endVal)
        std::cout << "int: impossible" << std::endl;
    else if(*endVal != '\0' && (*endVal != 'f' || endVal != &literal[literal.length() - 1]))
        std::cout << "int: impossible" << std::endl;
    else if((val > INT_MAX || val < INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
    {
        int toInt = static_cast<int>(val);
        std::cout << "int: " << toInt << std::endl;
    }
}

int getPrecision(const std::string &literal)
{
    size_t decimalPos = literal.find('.');
    if(decimalPos == std::string::npos)
        return 1;
    return literal.length() - decimalPos - 1;
}

void doubleCheck(const std::string &literal)
{
    if(checkEmpty(literal,"double"))
        return ;

    char *endVal;
    long double val = strtod(literal.c_str(),&endVal);
    
    if(&literal[0] == endVal)
        std::cout << "double: impossible" << std::endl;
    else if(*endVal != '\0' && (*endVal != 'f' || endVal != &literal[literal.length() - 1]))
        std::cout << "double: impossible" << std::endl;
    else
    {   
        int precision = getPrecision(literal);
        if(*endVal == 'f')
            precision -= 1;
        std::cout << std::fixed << std::setprecision(precision);
        std::cout << "double: " << val << std::endl;
    }
}

void floatCheck(const std::string &literal)
{   
    if(checkEmpty(literal,"float"))
        return ;

    char *endVal;
    long double val = strtod(literal.c_str(),&endVal);
    
    if(&literal[0] == endVal)
        std::cout << "double: impossible" << std::endl;
    else if(*endVal != '\0' && (*endVal != 'f' || endVal != &literal[literal.length() - 1]))
        std::cout << "double: impossible" << std::endl;
    else
    {   
        int precision = getPrecision(literal);
        if(*endVal == 'f')
            precision -= 1;
        float toFloat = static_cast<float>(val);
        std::cout << std::fixed << std::setprecision(precision);
        std::cout << "float: " << toFloat << "f" << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal){
    charCheck(literal);
    intCheck(literal);
    floatCheck(literal);
    doubleCheck(literal);
}