#include <iostream>
#include <cmath>

class Fixed{
    private:
        bool isFloat;
        int number;
        static const int bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(int const num);
        Fixed(float const floatNum);
        Fixed &operator=(const Fixed&copy);
        friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
        float toFloat(void)const;
        int toInt(void)const;
};