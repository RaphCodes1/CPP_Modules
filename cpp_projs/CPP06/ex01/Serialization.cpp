#include "Serialization.hpp"

Serialization::Serialization(){};

Serialization::~Serialization(){};

// 1. unsigned long is an unsigned integer type
/* 2. reinterpret cast performs a low-level, unsafe conversion between unrelated pointer types
or between a pointer and an integer. tells compiler to reinterpret the raw bit pattern of a variable as
a different type */

unsigned long Serialization::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
};

Data* Serialization::deserialize(unsigned long raw)
{
    return reinterpret_cast<Data *>(raw);
};