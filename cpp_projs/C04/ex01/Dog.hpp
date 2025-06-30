#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal, public Brain{
    private:
        Brain *attribute;
    public:
        Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &copy);
        void makeSound() const;
        std::string getType() const;
        virtual ~Dog();
};

#endif