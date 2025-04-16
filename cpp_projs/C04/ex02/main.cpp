// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Dog myDog;
    Cat myCat;

    std::cout << myDog.getType() << " " << std::endl;
    std::cout << myCat.getType() << " " << std::endl;
    myDog.makeSound();
    myCat.makeSound();

    return (0);
}