#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        virtual void makeSound() const;
        virtual std::string getType() const;
        virtual ~Animal();
};

#endif