#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
    public:
        Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &copy);
        virtual void makeSound() const;
        std::string getType() const;
        virtual ~Dog();
};

#endif