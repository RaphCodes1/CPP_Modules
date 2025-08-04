#include "Cat.hpp"

void Cat::makeSound() const{
    std::cout << "Meooowwww" << std::endl;
}

std::string Cat::getType() const{
    return _type;
}

Cat::Cat(): Animal(), attribute(new Brain()) {
    _type = "Cat";
    std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src), attribute(new Brain(*src.attribute)){
    _type = src._type;
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
    std::cout << "Cat Assignment Operator called" << std::endl;
    if (this != &copy) {
        if (attribute) {
            delete attribute; // Clean up existing attribute
        }
        attribute = new Brain(*(copy.attribute));
        _type = copy._type;
    }
    return *this;
}

Cat::~Cat(){
    std::cout << "Cat Destructor called" << std::endl;
    delete attribute; // Clean up dynamically allocated Brain`
}

Brain* Cat::getBrain() const{
    return attribute; // Return the Brain pointer
}