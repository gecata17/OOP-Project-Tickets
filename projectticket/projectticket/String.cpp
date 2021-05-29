
#include "String.h"

void String::copy(const String& other)
{
    this->size = other.size;
    this->data = new char[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        this->data[i] = other.data[i];
    }
}

void String::clear()
{
    delete[] data;
}

String::String()
{
    this->data = nullptr;
    this->size = 0;
}

String::String(const String& other)
{
    copy(other);
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

String::~String()
{
    clear();
}

String::String(const size_t size)
{
    this->size = size;
    this->data = new char[this->size];
}

String::String(const char* data)
{
    this->size = strlen(data);
    this->data = new char[this->size+1];
    strcpy_s(this->data, this->size + 1, data);
}

size_t String::getSize() const
{
    return this->size;
}


const char& String::operator[](size_t index) const
{
    return data[index];  
}

char& String::operator[](size_t index)
{
    return data[index];
}

String& String::operator+=(const String& other)
{
    return *this = *this + other;
}

String String::operator+(const String& other)
{
    String sum(*this);
    sum += other;

    return sum;
}



String& String::concat(const String& other)
{
    for (size_t i = 0; i < size; i++)
    {
        this->data[this->size] = data[size];
    }

    for (size_t i = this->size; i = this->size < other.size; i++)
    {
        this->data[this->size] = other.data[other.size];
        this->size++;
    }
    return *this;
}

bool String::empty()
{
    if (this->data == nullptr)
    {
        std::cout << "Empty string" << std::endl;
        return true;
    }
    return false;
}





bool String::operator==(const String& other)
{
    int i = 0;
    for (; this->data[i] != '\0'; i++)
    {
        if (this->data[i] != other.data[i])
        {
            return false;
        }
    }
    if (other.data[i] != '\0')
    {
        return false;
    }

    return true;
}

void String::append(const String& other)
{
    String resultString;
    resultString.size = this->size + other.size;
    resultString = new char[resultString.size];
    size_t i = 0;
    for (i; i < this->size; i++)
    {
        resultString.data[i] = this->data[i];
    }
    for (size_t j = 0; j < other.size; j++)
    {
        resultString.data[j] = other.data[j];
        ++i;
    }
    delete[] this->data;

    for (size_t k = 0; k < this->size; k++)
    {
        this->data[k] = resultString.data[k];
    }
}

void String::pushBack(const char& element)
{

    if (this->data == nullptr) {
        this->data = new char[1];
        this->data[0] = element;
        this->size = 1;
        return;
    }
    char* newStr = new char[this->size + 1];
    for (size_t i = 0; i < this->size; i++)
    {
        newStr[i] = data[i];
    }
    newStr[size] = element;

    size++;
    delete[] this->data;
    this->data = newStr;
}

void String::popback()
{
    if (this->data == nullptr)
    {
        std::cout << "Empty string" << std::endl;
        return;
    }
    --this->size;
    char* newStr = new char[this->size];

    for (size_t i = 0; i < this->size; i++)
    {
        newStr[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newStr;
}

unsigned String::find(const char* substring) const
{
    unsigned substringIndex = 0;
    for (size_t i = 0; i < this->size; i++)
    {
        unsigned firstOccur = i;
        if (this->data[i] == substring[0])
        {
            unsigned temp = i;
            while (this->data[temp] == substring[substringIndex])
            {
                temp++;
                substringIndex++;
                if (this->data[temp - 1] == substring[strlen(substring) - 1])
                {
                    return firstOccur;
                }
            }
        }
    }

    return -1;
}





std::istream& operator>>(std::istream& in, String& other)
{
    std::cout << "Enter string length: ";
    in >> other.size;
    std::cout << "Enter the string: " << std::endl;
    in.getline(other.data, other.size);
    return in;

}

std::ostream& operator<<(std::ostream& out, const String& other)
{
    for (size_t i = 0; i < other.size; ++i)
    {
        out << other.data[i];
    }
    return out;

}