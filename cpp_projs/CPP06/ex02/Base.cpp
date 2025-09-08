#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
    //std::cout << "Base Destructor Called" << std::endl;
};

Base *genA(void)
{
    return static_cast<Base *>(new A);
};
Base *genB(void)
{
    return static_cast<Base *>(new B);
};
Base *genC(void)
{
    return static_cast<Base *>(new C);
};

Base * Base::generate(void)
{       
    Base* (*generateRand[3])(void) = {
        &genA,
        &genB,
        &genC,
    };
    int randomNum = rand() % 3;

    return generateRand[randomNum]();
};

//dynamic_cast on a pointer returns NULL, if else is valid
void Base::identify(Base* p)
{
    if(dynamic_cast<A*>(p)){
        std::cout << "Identity A" << std::endl;
    } else if(dynamic_cast<B*>(p)){
        std::cout << "Identity B" << std::endl;
    } else if(dynamic_cast<C*>(p)){
        std::cout << "Identity C" << std::endl;
    }
    else
        std::cout << "Unknown Type" << std::endl;
}

//dynamic_cast on a reference throws a std.bad_cast exception, try catch block needed
void Base::identify(Base& p)
{
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "Identity A" << std::endl;
        return ;
    } catch(std::exception& e){}

    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "Identity B" << std::endl;
        return ;
    } catch(std::exception& e){}

    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "Identity C" << std::endl;
        return ;
    } catch(std::exception& e){}

    std::cout << "Unknown Type" << std::endl;
}