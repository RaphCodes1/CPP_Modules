#include "Fixed.hpp"

Fixed::Fixed(){
    // std::cout << "Default constructor called" << std::endl;
    this->number = 0;
    this->isFloat = false;
}

Fixed::~Fixed(){
    // std::cout << "Deconstructor called" << std::endl;
}

Fixed::Fixed(const int numInt)
{   
    isFloat = false;
    // std::cout << "Int constructor called" << std::endl;
    number = numInt;
}

Fixed::Fixed(const float numFloat)
{   
    isFloat = true;
    // std::cout << "Float constructor called" << std::endl;
    number = roundf(numFloat * (1 << bits));
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

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->isFloat = copy.isFloat;
    this->number = copy.number;
}

Fixed &Fixed::operator=(const Fixed &copy)
{   
    // std::cout << "Copy assignment operater called" << std::endl;
    if(this != &copy)
    {
        this->isFloat = copy.isFloat;
        this->number = copy.number;
    }
    return *this;
}

std::ostream&operator<<(std::ostream &out, const Fixed &fixed)
{   
    if(fixed.isFloat == true)
        out << fixed.number;
    else
        out << fixed.toFloat();
    return out;
}

// --------arithmetic operators------------ 

Fixed Fixed::operator*(const Fixed &copy)
{
    return Fixed(this->number * copy.number);
}

Fixed Fixed::operator+(const Fixed &copy)
{
    return Fixed(this->number + copy.number);
}

Fixed Fixed::operator-(const Fixed &copy)
{
    return Fixed(this->number - copy.number);
}

Fixed Fixed::operator/(const Fixed &copy)
{
    return Fixed(this->number / copy.number);
}

// ---------comparison operators-------------

Fixed Fixed::operator>(const Fixed &copy)
{   
    if(this->number > copy.number)
        this->number = 1;
    else
        this->number = 0;
    return Fixed(this->toFloat());
}

Fixed Fixed::operator<(const Fixed &copy)
{   
    if(this->number < copy.number)
        this->number = 1;
    else
        this->number = 0;
    return Fixed(this->toFloat());
}

Fixed Fixed::operator>=(const Fixed &copy)
{   
    if(this->number >= copy.number)
        this->number = 1;
    else
        this->number = 0;
    return Fixed(this->toFloat());
}

Fixed Fixed::operator<=(const Fixed &copy)
{   
    if(this->number <= copy.number)
        this->number = 1;
    else
        this->number = 0;
    return Fixed(this->toFloat());
}

Fixed Fixed::operator==(const Fixed &copy)
{   
    if(this->number == copy.number)
        this->number = 1;
    else
        this->number = 0;
    return Fixed(this->toFloat());
}

Fixed Fixed::operator!=(const Fixed &copy)
{   
    if(this->number != copy.number)
        this->number = 1;
    else
        this->number = 0;
    return Fixed(this->toFloat());
}

//---------increments and decrements ----------

Fixed Fixed::operator++(void)
{
    return Fixed(++this->number);
}

Fixed Fixed::operator++(int)
{
    return Fixed(this->number++);
}

Fixed Fixed::operator--(void)
{
    return Fixed(--this->number);
}

Fixed Fixed::operator--(int)
{
    return Fixed(this->number--);
}

Fixed Fixed::min(Fixed a, Fixed b)
{
    return (a.number < b.number) ? Fixed(a.number):Fixed(b.number);
}

Fixed Fixed::max(Fixed a, Fixed b)
{
    return (a.number > b.number) ? Fixed(a.number):Fixed(b.number);
}

Fixed const Fixed::minConst(const Fixed a, const Fixed b)
{
    return (a.number < b.number) ? Fixed(a.number):Fixed(b.number);
}

Fixed const Fixed::maxConst(const Fixed a, const Fixed b)
{
    return (a.number > b.number) ? Fixed(a.number):Fixed(b.number);
}
