#include "Fixed.hpp"

Fixed::Fixed(){
    num = 0;
    std::cout << "Default Constructor Called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Deconstructor Called"  << std::endl;
}

Fixed::Fixed(const Fixed &copy){
    std::cout << "Copy constructor called" << std::endl;
    if(this != &copy){
        this->num = copy.num;
    }
    setRawBits(constNum);
}

Fixed &Fixed::operator = (const Fixed &copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &copy){
        this->num = copy.getRawBits();
    }
    return *this;
}

void Fixed::setRawBits(int const raw){
    std::cout << "Copy assignment operator called" << std::endl;
    num = this->getRawBits() << raw;
}

int Fixed::getRawBits(void)const{
    std::cout << "getRawBits member function called" << std::endl;
    return num;
}
