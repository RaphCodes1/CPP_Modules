#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b(Fixed( 5.05f ) * Fixed( 2 ));
    Fixed const c(Fixed( 5.05f ) + Fixed( 2 ));
    Fixed const d(Fixed( 5.05f ) - Fixed( 2 ));
    Fixed const e(Fixed( 5.05f ) / Fixed( 2 ));
    Fixed const f(Fixed( 5.05f ) > Fixed( 2 ));
    Fixed const g(Fixed( 5.05f ) < Fixed( 2 ));
    Fixed const h(Fixed( 5.05f ) >= Fixed( 2 ));
    Fixed const i(Fixed( 5.05f ) <= Fixed( 2 ));
    Fixed const j(Fixed( 5.05f ) == Fixed( 5.05f ));
    Fixed const k(Fixed( 5.05f ) != Fixed( 2 ));

    
    std::cout <<  "A is: " << a << std::endl;
    std::cout <<  "A is: " << ++a << std::endl;
    std::cout <<  "A is: " << a++ << std::endl;
    std::cout <<  "A is: " << a << std::endl;
    std::cout <<  "A is: " << --a << std::endl;
    std::cout <<  "A is: " << a-- << std::endl;
    std::cout <<  "A is: " << a << std::endl;



    std::cout <<  "B is: " << b << std::endl;
    std::cout <<  "C is: " << c << std::endl;
    std::cout <<  "D is: " << d << std::endl;
    std::cout <<  "E is: " << e << std::endl;
    std::cout <<  "F is: " << f << std::endl;
    std::cout <<  "G is: " << g << std::endl;
    std::cout <<  "H is: " << h << std::endl;
    std::cout <<  "I is: " << i << std::endl;
    std::cout <<  "J is: " << j << std::endl;
    std::cout <<  "K is: " << k << std::endl;
}