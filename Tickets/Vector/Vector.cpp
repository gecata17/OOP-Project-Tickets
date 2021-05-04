#include "Vector.h"


template<class T>
void Vector<T>::copy(const Vector<T>& other)
{   
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new T[other.size];
    for (int i = 0; i < size; i++)
    {
        this->data[i] = other.data[i];
    }
}

template<class T>
void Vector<T>::destroy()
{
    delete[] this->data;
}