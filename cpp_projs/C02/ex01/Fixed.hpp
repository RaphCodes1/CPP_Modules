#include <iostream>
#include <cmath>

class Fixed{
    private:
        int number;
        static const int bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(int const num);
        Fixed(float const floatNum);
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed&copy);
        float toFloat(void)const;
        int toInt(void)const;
    };
    
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);