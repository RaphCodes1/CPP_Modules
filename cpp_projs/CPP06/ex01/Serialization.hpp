#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
#include <string>
#include <cstdint>
#include "Data.hpp"

class Serialization {
    private:
        Serialization();
        ~Serialization();
    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif