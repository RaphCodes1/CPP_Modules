#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    Fixed const c( Fixed( 10.05f ) + Fixed( 2 ) );
    std::cout << c << std::endl;

    Fixed const d( Fixed( 10 ) - Fixed( 2 ) );
    std::cout << d << std::endl;

    Fixed const e( Fixed( 10.05f ) / Fixed( 2 ) );
    std::cout << e << std::endl;

    // std::cout << "Static Min: " << Fixed::min(a,b) << std::endl; 
    // std::cout << "Static Max: " << Fixed::max(c,a) << std::endl; 
    // std::cout << "CONST Static Min: " << Fixed::min(a,b) << std::endl; 
    // std::cout << "CONST Static Max: " << Fixed::max(c,a) << std::endl; 
}