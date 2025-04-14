#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal, public Brain{
    private:
        Brain *attribute;
    public:
        Cat();
        void makeSound() const;
        std::string getType() const;
        ~Cat();
};

#endif