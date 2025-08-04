#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Deconstructor called" << std::endl;
}

Fixed::Fixed(int const num){
    std::cout << "Int constructor called" << std::endl;
    number = num * (1 << bits);
}

Fixed::Fixed(float const floatNum){
    std::cout << "Float constructor called" << std::endl;
    number = roundf(floatNum * (1 << bits));
}

Fixed::Fixed(const Fixed &copy)
{   
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{   
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &copy)
        this->number = copy.number;
    return *this;
}

int Fixed::toInt(void)const{
    return number >> bits;
}

float Fixed::toFloat(void) const {
    return (float)(number) / (1 << bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{   
    out << fixed.toFloat();
    return out;
}

void Fixed::setRawBits(int const raw){
    number = raw;
}

int Fixed::getRawBits(void)const{
    std::cout << "getRawBits member function called" << std::endl;
    return number;
}



