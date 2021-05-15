#pragma once

#include<cstring>
template <typename T>
class Vector {
private:
	T* data;
	size_t size;
	size_t capacity;
	void copy(const Vector<T>&);
	void destroy();
	void resize();
public:


	Vector();
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	~Vector();
	Vector(int capacity);
	Vector(const size_t size);
	void pushBack(const T& element);//add element at the back
	void popBack();//remove element at the back
	void pushFront(const T& element);//add element at the front
	void popFront();//remove element at the front

	bool empty() const;



	//index operator
	const T& operator[](size_t)const;
	T& operator[](size_t);



	//getters
	int getCapacity() const;
	int getSize() const;

	//print method
	void print() const;

};

template <class T>
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

template <class T>
void Vector<T>::destroy()
{
    delete[] this->data;
}

template <class T>
Vector<T>::Vector()
{
    this->data = nullptr;
    this->size = 0;
    this->capacity = 8;
}

template <class T>
Vector<T>::Vector(const Vector<T>& other)
{
    copy(other);
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}

template <class T>
Vector<T>::~Vector()
{
    destroy();
}

template <class T>
void Vector<T>::resize()
{
    T* temp = new T[this->capacity * 2];
    this->capacity *= 2;
    for (size_t i = 0; i < this->size; i++)
    {
        temp[i] = this->data[i];
    }
    this->destroy();
    this->data = temp;
}

template <class T>
Vector<T>::Vector(int capacity)
{
    if (capacity < 0)
    {
        this->capacity = 0;
    }
    else
    {
        this->capacity = capacity;
    }
    size = 0;
    data = new T[this->capacity];
}

template <class T>
Vector<T>::Vector(const size_t size)
{
    this->size = size;
    this->data = new T[size];
}

template <class T>
void Vector<T>::popBack()
{
    if (this->data == nullptr)
    {
        std::cout << "Vector is empty!" << std::endl;
        return;
    }

    --this->size;
    T* array = new T[this->size];

    for (size_t i = 0; i < this->size; i++)
    {
        array[i] = this->data[i];
    }

    delete[] this->data;
    this->data = array;
}
template <class T>
void Vector<T>::pushBack(const T& element)
{
    if (this->data == nullptr)
    {
        ++this->size;
        this->data = new T[size];
        this->data[0] = element;
        return;
    }

    T* array = new T[this->size + 1];
    for (size_t i = 0; i < this->size; ++i)
    {
        array[i] = this->data[i];
    }
    array[size] = element;

    if (size > capacity)
    {
        resize();
    }

    ++size;
    delete[] this->data;
    this->data = array;
}
template <class T>
void Vector<T>::pushFront(const T& element)
{
    if (this->data == nullptr)
    {
        ++this->size;
        this->data = new T[this->size];
        this->data[0] = element;
        return;
    }
    T* array = new T[size + 1];
    for (size_t i = 1; i < this->size + 1; i++)
    {
        array[i] = this->data[i - 1];
    }
    array[0] = element;

    if (size > capacity)
    {
        resize();
    }

    ++size;
    delete[] this->data;
    this->data = array;
}

template <class T>
void Vector<T>::popFront()
{
    if (this->data == nullptr)
    {
        std::cout << "Vector is empty!" << std::endl;
        return;
    }

    --this->size;
    T* array = new T[this->size];

    for (size_t i = this->size - 1; i >= 0; i--)
    {
        array[i] = this->data[i];
    }

    delete[] this->data;
    this->data = array;
}

template <class T>
bool Vector<T>::empty() const
{
    return data != nullptr && size == 0;
   
}

template <class T>
const T& Vector<T>::operator[](size_t index) const
{
    

    if (index < size)
    {
        return data[index];
    }
    //exception
    throw "Index too large";
  
    
}

template <class T>
T& Vector<T>::operator[](size_t index)
{
    if (index < size)
    {
        return data[index];
    }
    //exception
    throw "Index too large";
}


template <class T>
int Vector<T>::getCapacity() const
{
    return this->capacity;
}

template <class T>
int Vector<T>::getSize() const
{
    return this->size;
}

template <class T>
void Vector<T>::print() const
{
    if (this->data == nullptr)
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}
