#pragma once

#include<iostream>
#include<cstring>
template <typename T>
class Vector{
private:
   T * data;
   size_t size;
   size_t capacity;

public:
    void copy(const Vector<T>&);
	void destroy();
	void resize();

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
	
	bool empty();



	//index operator
	const T& operator[](int)const;
	T& operator[](int);

	

	//getters
	int getCapacity() const;
	int getSize() const;

	//print method
	void print() const;
   
};
