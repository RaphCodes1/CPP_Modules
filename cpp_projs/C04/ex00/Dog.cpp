#include "Dog.hpp"

void Dog::makeSound() const{
    std::cout << "Woof Woof Dawg" << std::endl;
}

std::string Dog::getType() const{
    return type;
}

Dog::Dog(){
    type = "Dog";
}

Dog::~Dog(){
    std::cout << "Dog Deconstructor called" << std::endl;
}