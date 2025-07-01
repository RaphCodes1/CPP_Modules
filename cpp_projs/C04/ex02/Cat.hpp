#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private:
        Brain *attribute;
    public:
        Cat();
        Cat(const Cat &src);
        Cat &operator=(const Cat &copy);
        void makeSound() const;
        std::string getType() const;
        virtual ~Cat();
        Brain* getBrain() const;// to access Brain
};

#endif