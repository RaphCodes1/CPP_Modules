#include "conversion.hpp"

ScalarConverter::ScalarConverter(){
    //std::cout << "ScalarConverter Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(){
    //std::cout << "ScalarConverter Destructor called" << std::endl;
}

void charCheck(const std::string &literal)
{   
    bool numOnly = true;
    for(size_t i = 0; i < literal.length(); i++)
    {
        if(!isdigit(literal[i]))
        {
            numOnly = false;
            break;
        }
    }
    if(numOnly)
    {   
        std::cout << "number 1" << std::endl;
        const char * convToChar = literal.c_str();
        int convToASCII = atoi(convToChar);
        if(convToASCII == '\0' || convToASCII == '\t' || convToASCII == '\n'
            || convToASCII == '\r' || convToASCII == '\e')
        {
            std::cout << "char: non displayable" << std::endl;
            return ;
        }
        else
            std::cout << "char: '" << static_cast<char>(convToASCII) << "'" << std::endl;
    }
    else if(!numOnly && literal.length() == 1 && !isdigit(literal[0]))
    {   
        std::cout << "number 2" << std::endl;
        std::cout << "char: '" << literal << "'" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
}

void intCheck(const std::string &literal)
{
    for(size_t i = 0; i < literal.length() - 1; i++)
    {
        if(!isdigit(literal[i]))
        {
            std::cout << "int: impossible" << std::endl;
            return ;
        }
    }
    int converted = atoi(literal.c_str());
        std::cout << "int: " << converted << std::endl;
    return ;
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

// void charCheck(const std::string &literal)
// {
//     // Handle single character literals first
//     if (literal.length() == 1 && !isdigit(literal[0]))
//     {
//         char c = literal[0];
//         if (isprint(c)) {
//             std::cout << "char: '" << c << "'" << std::endl;
//         } else {
//             std::cout << "char: Non displayable" << std::endl;
//         }
//     }
//     // Handle numeric literals
//     else 
//     {
//         // Use a more robust way to check if it's a valid number
//         char* end;
//         double val = strtod(literal.c_str(), &end);
        
//         // Check if the whole string was a valid number
//         if (*end != '\0' && (*end != 'f' || end != &literal[literal.length()-1])) {
//              std::cout << "char: impossible" << std::endl;
//              return;
//         }

//         int ascii_val = static_cast<int>(val);
//         if (val < 0 || val > 127) { // Check if it's outside ASCII range
//             std::cout << "char: impossible" << std::endl;
//         } else if (isprint(ascii_val)) {
//             std::cout << "char: '" << static_cast<char>(ascii_val) << "'" << std::endl;
//         } else {
//             std::cout << "char: Non displayable" << std::endl;
//         }
//     }
// }