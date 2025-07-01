#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    _type = "WrongCat";
    std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) {
    _type = src._type;
    std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
    std::cout << "WrongCat Assignment Operator called" << std::endl;
    if (this != &copy) {
        _type = copy._type;
    }
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat sound: meowwwww meowwww" << std::endl;
}

std::string WrongCat::getType() const {
    return _type;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called" << std::endl;
}