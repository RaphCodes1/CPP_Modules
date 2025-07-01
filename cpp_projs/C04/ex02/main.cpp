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

    i = -1;
    while(++i < 10)
    {
        arrayAnimal[i]->makeSound();
    }

    i = -1;
    while(++i < 10)
    {
        delete arrayAnimal[i];
    }   
    
    Dog base;
    base.getBrain()->setIdea(0, "I want to eat");
    std::cout << "base idea " << base.getBrain()->getIdea(0) << std::endl;
    {
        Dog clone;
        clone = base;
        std::cout << "clone idea: " << clone.getBrain()->getIdea(0) << std::endl;
        clone.getBrain()->setIdea(0, "I want to play");
        std::cout << "base idea: " << base.getBrain()->getIdea(0) << std::endl;
        std::cout << "clone idea: " << clone.getBrain()->getIdea(0) << std::endl;
        std::cout << "clone's Brain address: " << clone.getBrain() << std::endl;
        std::cout << "base's Brain address: " << base.getBrain() << std::endl;
    }
    std::cout << "base idea " << base.getBrain()->getIdea(0) << std::endl;
        return (0);
}