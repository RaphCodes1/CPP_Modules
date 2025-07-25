#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private:
        Brain *attribute;
    public:
        Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &copy);
        virtual void makeSound() const;
        std::string getType() const;
        virtual ~Dog();
        Brain* getBrain() const; // to access Brain
};

#endif