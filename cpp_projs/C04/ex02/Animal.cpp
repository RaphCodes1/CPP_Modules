#include "Animal.hpp"

void Animal::makeSound() const{
    std::cout << "Random Animal Sound" << std::endl;
}

std::string Animal::getType() const{
    return type;
}

Animal::Animal(){
    type = "";
}

Animal::~Animal(){
    std::cout << "Animal Deconstructor called" << std::endl;
}