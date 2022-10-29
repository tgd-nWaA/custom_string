#include "String.h"

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

String::String()
    : length(0), str(nullptr){}

//todo test if it works with length == 1
String::String(const char _char)
    : length(1), str(new char[2])
{
    str[0] = _char; str[1] = '\0';
}

String::String(const char* other)
    : String()
{
    if (other != nullptr)
    {
        length = strlen(other);
        str = new char[length + 1];
        std::copy(other, other + length + 1, str);
    }
}

String::String(const std::string& other)
    : String(other.c_str()) {};

String::String(const String& other)
    : String(other.c_str()) {};

//implemented copy-and-swap idiom
 String& String::operator=(String other) &
 {
     swap(*this, other);

     return *this;
 }

String::String(String&& other) noexcept
    : String()
{
    std::cout << "moved" << "\n";
    swap(*this, other);
}

String::~String()
{
    cleanUp();
};

const char& String::operator[](const size_t i) const
{
    if (i >= length)
        throw std::out_of_range("Out of bounds!");

    return str[i];
}

char& String::operator[](const size_t i)
{
    if (i >= length)
        throw std::out_of_range("Out of bounds!");

    return str[i];
}

String& String::operator+=(const String& _other) &
{
    auto totalLength = length + _other.length;
    char* buffer = new char[totalLength + 1];

    std::copy(str, str + length, buffer);
    std::copy(_other.str, _other.str + _other.length, buffer + length);
    buffer[totalLength] = '\0';

    std::swap(str, buffer);
    length = totalLength;

    delete[] buffer;

    return *this;
}
    
String String::toLowerCase() const
{
    String buffer = *this;

    for (auto& c : buffer) {
        tolower(c);
    }

    return buffer;
}

String String::toUpperCase() const
{
    String buffer = *this;

    for (auto& c : buffer) {
        toupper(c);
    }

    return buffer;
}

void String::swap(String& first, String& second) // nothrow
{
    // by swapping the members of two objects,
    // the two objects are effectively swapped
    std::swap(first.length, second.length);
    std::swap(first.str, second.str);
}

void String::cleanUp()
{
    if (str != nullptr)
    {
        delete[] str;
        str = nullptr;
    }

    length = 0;
}

std::ostream& operator<<(std::ostream& _os, const String& _string)  
{
    for (int i = 0; i < _string.getLength(); i++)
    {
        _os << _string[i];
    }
    return _os;
}

const String operator+(String lhs, const String& rhs)
{
    return lhs += rhs;
}




