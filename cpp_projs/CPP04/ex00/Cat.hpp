#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat();
        Cat(const Cat &src);
        Cat &operator=(const Cat &copy);
        virtual void makeSound() const;
        std::string getType() const;
        virtual ~Cat();
};

#endif