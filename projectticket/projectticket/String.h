#pragma once
#include<iostream>
#include<cstring>
class String {
private:
	char* data;
	size_t size;
public:
	void copy(const String& other);
	void clear();
	String();
	String(const String&);
	String& operator=(const String&);
	~String();
	String(const size_t size);
	String(const char* data);



	int getSize() const;
	String& concat(const String& other);
	bool empty();


	const char operator[](int)const;
	char operator[](int);
	String& operator+=(const String&);
	String operator+(const String&);

	void append(const String&);
	void pushBack(const char& element);
	void popback();

	unsigned find(const char* substring) const;
	void compare(const String&);
	void swap(const String&);

	friend std::istream& operator>>(std::istream& in, String& other);
	friend std::ostream& operator<<(std::ostream& out, const String& other);

};