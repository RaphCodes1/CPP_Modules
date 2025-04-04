#include <iostream>
#include <string>

class Fixed {
    private:
        int num;
        static const int constNum = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator = (const Fixed &copy);
        int getRawBits(void)const;
        void setRawBits(int const raw);
};