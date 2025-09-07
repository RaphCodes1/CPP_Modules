#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base{
    public:
        virtual ~Base();
        Base * generate(void);
        void identify(Base *p);
        void identify(Base &p);
};

#endif