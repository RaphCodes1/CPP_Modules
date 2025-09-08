#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));

    Base* ranGen = NULL;

    Base* randGenPointer = ranGen->generate();
    Base& randReference = *randGenPointer;
    
    std::cout << "Identifying Random: ";
    randGenPointer->identify(randGenPointer);

    std::cout << "Identifying Random: ";
    randReference.identify(randReference);
}
