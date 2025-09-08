#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base *genA(void)
{
    return new A;
};
Base *genB(void)
{
    return new B;
};
Base *genC(void)
{
    return new C;
};

Base* generate(void)
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
void identify(Base* p)
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
void identify(Base& p)
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

int main()
{
    srand(time(0));

    Base* randGenPointer = generate();
    Base& randReference = *randGenPointer;
    
    std::cout << "Identifying Random: ";
    identify(randGenPointer);

    std::cout << "Identifying Random: ";
    identify(randReference);

    delete randGenPointer;
}
