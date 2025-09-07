#include "Serialization.hpp"

Serialization::Serialization(){};

Serialization::~Serialization(){};

// 1. uintptr_t is an unsigned integer type
/* 2. reinterpret cast performs a low-level, unsafe conversion between unrelated pointer types
or between a pointer and an integer. tells compiler to reinterpret the raw bit pattern of a variable as
a different type */

uintptr_t Serialization::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
};

Data* Serialization::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
};