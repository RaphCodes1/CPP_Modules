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

    std::cout << "comparison: " << Fixed(b <= a) << std::endl;
    
    std::cout << "min max: " << Fixed::max(a,b) << std::endl;
}