#include "Cat.hpp"

void Cat::makeSound() const{
    std::cout << "Meooowwww" << std::endl;
}

std::string Cat::getType() const{
    return _type;
}

Cat::Cat():Animal() {
    _type = "Cat";
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &src):Animal(src) {
    _type = src._type;
    std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
    std::cout << "Cat Assignment Operator called" << std::endl;
    if (this != &copy) {
        _type = copy._type;
    }
    return *this;
}

Cat::~Cat(){
    std::cout << "Cat Destructor called" << std::endl;
}