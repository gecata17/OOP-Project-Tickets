#include "String.h"

void String::copy(const String& other)
{
    this->size = other.size;
    this->data = new char[other.size];
    for (size_t i = 0; i < size; i++)
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
}

String::String(const char* data)
{
    this->data = new char[this->size];
    
}

int String::getSize() const
{
    return this->size;
}


const char String::operator[](int index) const
{
    if (index >= 0 && index < size)
    {
        return data[index];
    }
    return 0;
}

char String::operator[](int index)
{
    if (index >= 0 && index < size)
    {
        return data[index];
    }
    return 0;
}



String& String::concat(const String& other)
{
    char* tmp = new char[size];
    strcpy_s(tmp, size +1,data);

    int i = strlen(tmp);
    int k = 0;

    this->size += other.size;

    delete[] this->data;
    this->data = new char[this->size];

    strcpy_s(data, size + 1,tmp);

    for (i; i < this->size; i++)
    {
        this->data[i] = other.data[k];
        k++;
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

void String::compare(const String& other)
{
    for (int i = 0; this->data[i] != '\0'; ++i)
    {
        if (this->data[i] != other.data[i])
        {
            std::cout << "First is not equal to second" << std::endl;
            if (this->data[i] > other.data[i])
            {
                std::cout << " First is greater than second" << std::endl;
            }
            else
            {
                std::cout << "Second is greater than" << std::endl;
            }
        }
        else
        {
            std::cout << "First is equalt to" << std::endl;
        }
    }
}

void String::swap(const String& other)
{

    char* swapper = new char[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        swapper[i] = this->data[i];
    }
    this->data = new char[strlen(data) + 1];
    for (size_t i = 0; data[i]; ++i)
    {
        this->data[i] = data[i];
    }
    this->data[strlen(data)] = '\0';

    for (size_t i = 0; i < this->size; i++)
    {
        other.data[i] = swapper[i];
    }
    delete[] swapper;
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
    }
    --this->size;
    char* newStr = new char[this->size];
    for (size_t i = 0; i < this->size; i++)
    {
        newStr[i] = data[i];
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
    //in.clear()
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