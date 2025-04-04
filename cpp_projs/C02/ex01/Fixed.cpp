#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Deconstructor called" << std::endl;
}

Fixed::Fixed(int const num){
    isFloat = false;
    std::cout << "Int constructor called" << std::endl;
    number = num;
}

Fixed::Fixed(float const floatNum){
    isFloat = true;
    std::cout << "Float constructor called" << std::endl;
    number = roundf(floatNum * (1 << bits));
}

Fixed::Fixed(const Fixed &copy)
{   
    std::cout << "Copy constructor called" << std::endl;
    this->isFloat = copy.isFloat;
    this->number = copy.number;
}

Fixed &Fixed::operator=(const Fixed &copy)
{   
    std::cout << "Copy assignment operater called" << std::endl;
    if(this != &copy)
    {
        this->isFloat = copy.isFloat;
        this->number = copy.number;
    }
    return *this;
}

int Fixed::toInt(void)const{
    if(isFloat)
        return number >> bits;
    else
        return number;
}

float Fixed::toFloat(void) const {
    return (float)(number) / (1 << bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{   
    if(fixed.isFloat == true)
        out << fixed.toFloat();
    else
        out << fixed.number;
    return out;
}



