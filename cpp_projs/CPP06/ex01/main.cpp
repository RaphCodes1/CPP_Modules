#include "Serialization.hpp"
#include "Data.hpp"

int main(){

    Data myData;
    myData.text = "Hello there world!";
    myData.value = 42;

    Data *pointerData = &myData;
    unsigned long addressAsInt = Serialization::serialize(pointerData);

    std::cout << "Original Pointer: " << pointerData << std::endl;
    std::cout << "Serialized to unsigned int: " << addressAsInt << std::endl;

    Data *backToPointer = Serialization::deserialize(addressAsInt);
    
    std::cout << "Deserialized back to Data Pointer: " << backToPointer << std::endl;

    return 0;
}