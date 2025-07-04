#include "Dog.hpp"

void Dog::makeSound() const{
    std::cout << "Woof Woof Dawg" << std::endl;
}

std::string Dog::getType() const{
    return _type;
}

Dog::Dog(): Animal(), attribute(new Brain()) {
    _type = "Dog";
    std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src), attribute(new Brain(*src.attribute)){
    _type = src._type;
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy) {
    std::cout << "Dog Assignment Operator called" << std::endl;
    if (this != &copy) {
        if (attribute) {
            delete attribute; // Clean up existing attribute
        }
        attribute = new Brain(*(copy.attribute));
        _type = copy._type;
    }
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog Destructor called" << std::endl;
    delete attribute; // Clean up dynamically allocated Brain
}

Brain* Dog::getBrain() const{
    return attribute; // Return the Brain pointer
}