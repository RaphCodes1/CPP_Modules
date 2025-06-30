#include "Dog.hpp"

void Dog::makeSound() const{
    std::cout << "Woof Woof Dawg" << std::endl;
}

std::string Dog::getType() const{
    return _type;
}

Dog::Dog():Animal() {
    _type = "Dog";
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &src):Animal(src) {
    _type = src._type;
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
    std::cout << "Dog Assignment Operator called" << std::endl;
    if (this != &copy) {
        _type = copy._type;
    }
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
}