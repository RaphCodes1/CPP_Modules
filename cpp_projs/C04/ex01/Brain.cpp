#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
    std::cout << "Brain Copy Constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = src.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &copy) {
    std::cout << "Brain Assignment Operator called" << std::endl;
    if (this != &copy) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = copy.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain Destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}