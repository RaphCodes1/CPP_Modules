#include "Fixed.hpp"

int main()
{
    // Fixed a;
    // Fixed const b(Fixed( 5.05f ) * Fixed( 2 ));
    // Fixed const c(Fixed( 5.05f ) + Fixed( 2 ));
    // Fixed const d(Fixed( 5.05f ) - Fixed( 2 ));
    // Fixed const e(Fixed( 5.05f ) / Fixed( 2 ));
    // Fixed const f(Fixed( 5.05f ) > Fixed( 2 ));
    // Fixed const g(Fixed( 5.05f ) < Fixed( 2 ));
    // Fixed const h(Fixed( 5.05f ) >= Fixed( 2 ));
    // Fixed const i(Fixed( 5.05f ) <= Fixed( 2 ));
    // Fixed const j(Fixed( 5.05f ) == Fixed( 5.05f ));
    // Fixed const k(Fixed( 5.05f ) != Fixed( 2 ));

    // std::cout << "Static Min: " << Fixed::min(c,b) << std::endl; 
    // std::cout << "Static Max: " << Fixed::max(d,e) << std::endl; 
    // std::cout << "CONST Static Min: " << Fixed::min(c,b) << std::endl; 
    // std::cout << "CONST Static Max: " << Fixed::max(d,e) << std::endl; 
    
    // std::cout <<  "A is: " << a << std::endl;
    // std::cout <<  "A is: " << ++a << std::endl;
    // std::cout <<  "A is: " << a << std::endl;
    // std::cout <<  "A is: " << a++ << std::endl;
    // std::cout <<  "A is: " << a << std::endl;
    // std::cout <<  "A is: " << --a << std::endl;
    // std::cout <<  "A is: " << a << std::endl;
    // std::cout <<  "A is: " << a-- << std::endl;
    // std::cout <<  "A is: " << a << std::endl;



    // std::cout <<  "B is: " << b << std::endl;
    // std::cout <<  "C is: " << c << std::endl;
    // std::cout <<  "D is: " << d << std::endl;
    // std::cout <<  "E is: " << e << std::endl;
    // std::cout <<  "F is: " << f << std::endl;
    // std::cout <<  "G is: " << g << std::endl;
    // std::cout <<  "H is: " << h << std::endl;
    // std::cout <<  "I is: " << i << std::endl;
    // std::cout <<  "J is: " << j << std::endl;
    // std::cout <<  "K is: " << k << std::endl;

    


    Fixed a;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    Fixed const b( Fixed( 5.05f ) * Fixed( 100000 ) );
    std::cout << b << std::endl;
    
    Fixed const c( Fixed( 10.05f ) + Fixed( 2 ) );
    std::cout << c << std::endl;

    Fixed const d( Fixed( 10.05f ) - Fixed( 2 ) );
    std::cout << d << std::endl;

    Fixed const e( Fixed( 10.05f ) / Fixed( 2 ) );
    std::cout << e << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;

    // std::cout << "Static Min: " << Fixed::min(a,b) << std::endl; 
    // std::cout << "Static Max: " << Fixed::max(c,a) << std::endl; 
    // std::cout << "CONST Static Min: " << Fixed::min(a,b) << std::endl; 
    // std::cout << "CONST Static Max: " << Fixed::max(c,a) << std::endl; 
}