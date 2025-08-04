#include "Animal.hpp"

void Animal::makeSound() const{
    std::cout << "Random Animal Sound" << std::endl;
}

std::string Animal::getType() const{
    return _type;
}

Animal::Animal():_type("default"){
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal &src):_type(src._type){
    std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy){
    std::cout << "Animal Assignment Operator called" << std::endl;
    if (this != &copy) {
        _type = copy._type;
    }
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal Destructor called" << std::endl;
}