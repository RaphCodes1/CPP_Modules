#include "Array.hpp"

template <typename T>
Array<T>::Array():_elements(NULL), _size(0){}

template <typename T>
Array<T>::~Array(){}

template <typename T>
Array<T>::Array(unsigned int size):_elements(new T[size]()), _size(size){}

template <typename T>
Array<T>::Array(const Array<T> &src):_elements(src._elements), _size(src._size){}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src){
    if(this != &src)
    {
        Array<T>::operator=(src);
        this->_elements = src._elements;
        this->_size = src._size;
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
    if (index > _size)
        throw std::exception();
    return _elements[index];
}

template <typename T>
int Array<T>::size(){
    return _size;
}