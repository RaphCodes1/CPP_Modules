#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <cmath>

class ScalarConverter{
    private:
        ScalarConverter();
        ~ScalarConverter();

    public:
        static void convert(const std::string &literal);
};


#endif