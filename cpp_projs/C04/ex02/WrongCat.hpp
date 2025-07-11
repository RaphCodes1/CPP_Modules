#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const WrongCat &src);
        WrongCat &operator=(const WrongCat &copy);
        void makeSound() const;
        std::string getType() const;
        virtual ~WrongCat();
};

#endif
