#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* arrayAnimal[10];
    int i = -1;
    while(++i < 10)
    {
        if(i < 5)
            arrayAnimal[i] = new Dog();
        else if(i >= 5)
            arrayAnimal[i] = new Cat();
    }
    i = -1;
    while(++i < 10)
    {
        std::cout << arrayAnimal[i]->getType() << "\n";
    }

    delete arrayAnimal;

    return (0);
}