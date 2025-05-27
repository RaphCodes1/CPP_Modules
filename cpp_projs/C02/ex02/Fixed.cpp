#include "Fixed.hpp"

Fixed::Fixed(){
    // std::cout << "Default constructor called" << std::endl;
    this->number = 0;
}

Fixed::~Fixed(){
    // std::cout << "Deconstructor called" << std::endl;
}

Fixed::Fixed(const int numInt)
{   
    number = numInt * (1 << bits);
}

Fixed::Fixed(const float numFloat)
{   
    number = roundf(numFloat * (1 << bits));
}

int Fixed::toInt(void)const{
    return number >> bits;
}

float Fixed::toFloat(void) const {
    return (float)(number) / (1 << bits);
}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{   
    // std::cout << "Copy assignment operator called" << std::endl;
    if(this != &copy)
        this->number = copy.number;
    return *this;
}

std::ostream&operator<<(std::ostream &out, const Fixed &fixed)
{   
    out << fixed.toFloat();
    return out;
}

// --------arithmetic operators------------ 

Fixed Fixed::operator*(const Fixed &copy)
{   
    Fixed res;
    res.number = (this->number * copy.number) >> res.bits;
    return res;
}

Fixed Fixed::operator+(const Fixed &copy)
{
    Fixed res;
    res.number = (this->number + copy.number);
    return res;
}

Fixed Fixed::operator-(const Fixed &copy)
{
    Fixed res;
    res.number = (this->number - copy.number);
    return res;
}

Fixed Fixed::operator/(const Fixed &copy)
{
    Fixed res;
    res.number = ((this->number << res.bits) / copy.number);
    return res;
}

// ---------comparison operators-------------

bool Fixed::operator>(const Fixed &copy)const
{   
    return this->number > copy.number;
}

bool Fixed::operator<(const Fixed &copy)const
{   
    return this->number < copy.number;
}

bool Fixed::operator>=(const Fixed &copy)const
{   
    return this->number >= copy.number;
}

bool Fixed::operator<=(const Fixed &copy)const
{   
    return this->number <= copy.number;
}

bool Fixed::operator==(const Fixed &copy)const
{   
    return this->number == copy.number;
}

bool Fixed::operator!=(const Fixed &copy)const
{   
    return this->number != copy.number;
}

//---------increments and decrements ----------

Fixed Fixed::operator++(void)
{   
    ++this->number;
    return *this;
}

Fixed Fixed::operator++(int)
{   
    Fixed temp = *this;
    this->number++;
    return temp;
}

Fixed Fixed::operator--(void)
{
    --this->number;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->number--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if(a < b)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{  
    if(a > b)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a:b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a:b);
}
