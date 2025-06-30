#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <iostream>
#include <string>
class WrongAnimal {
    protected:
        std::string _type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &src);
        WrongAnimal &operator=(const WrongAnimal &copy);
        void makeSound() const;
        std::string getType() const;
        virtual ~WrongAnimal();
};
#endif