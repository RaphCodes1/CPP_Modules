#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* arrayAnimal[2];
    arrayAnimal[0] = new Dog();
    arrayAnimal[1] = new Cat();

    arrayAnimal[0]->makeSound();
    arrayAnimal[0]->getType();

    arrayAnimal[1]->makeSound();
    arrayAnimal[1]->getType();

    delete arrayAnimal[0];
    delete arrayAnimal[1];

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