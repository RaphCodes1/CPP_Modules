#include "Cat.hpp"

void Cat::makeSound() const{
    std::cout << "Meooowwww" << std::endl;
}

std::string Cat::getType() const{
    return type;
}

Cat::Cat(){
    type = "Cat";
}

Cat::~Cat(){
    std::cout << "Cat Deconstructor called" << std::endl;
}