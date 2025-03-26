#include <iostream>
#include <string>

class Harl
{   
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        Harl();
        ~Harl();
        typedef void(Harl::*debugPtr)();
        typedef void(Harl::*infoPtr)();
        typedef void(Harl::*warningPtr)();
        typedef void(Harl::*errorPtr)();
        void complain(std::string level);
};