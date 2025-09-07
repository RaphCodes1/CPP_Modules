#include "Base.hpp"

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
    Base* (*generateRand[])(void){
        &genA,
        &genB,
        &genC,
    };
    int randomNum = rand() % 3;

    return generateRand[randomNum]();
};

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

void Base::identify(Base& p)
{
    //   
}