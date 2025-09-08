#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));

    A a;
    B b;
    Base* randGen = NULL;

    Base* randomPointer = &a;
    Base& randomReference = b;

    Base* genPointer = randGen->generate();

    std::cout << "Identifying pointer to A: ";
    randomPointer->identify(randomPointer);

    std::cout << "Identifying reference to B: ";
    randomReference.identify(randomReference);
    
    std::cout << "Identifying Random: ";
    genPointer->identify(genPointer);
}
