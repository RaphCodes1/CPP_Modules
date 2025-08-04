#include <iostream>
#include <cmath>

class Fixed{
    private:
        int number;
        static const int bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const int numInt);
        Fixed(const float numFloat);
        Fixed(const Fixed &copy);
        Fixed&operator=(const Fixed &copy);
        int toInt(void) const;
        float toFloat(void) const;
        Fixed operator*(const Fixed &copy);
        Fixed operator+(const Fixed &copy);
        Fixed operator-(const Fixed &copy);
        Fixed operator/(const Fixed &copy);
        bool  operator>(const Fixed &copy)const;
        bool  operator<(const Fixed &copy)const;
        bool  operator>=(const Fixed &copy)const;
        bool  operator<=(const Fixed &copy)const;
        bool  operator==(const Fixed &copy)const;
        bool  operator!=(const Fixed &copy)const;
        Fixed operator++(void);
        Fixed operator++(int);
        Fixed operator--(void);
        Fixed operator--(int);
        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        int getRawBits(void)const;
        void setRawBits(int const raw);
};
std::ostream&operator<<(std::ostream &out, const Fixed &fixed);