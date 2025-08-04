#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &src);
        Brain &operator=(const Brain &copy);
        ~Brain();

        void setIdea(int index, const std::string &idea);
        std::string getIdea(int index) const;
};

#endif
