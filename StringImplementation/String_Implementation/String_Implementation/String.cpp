#include "String.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <algorithm>

using std::ostream;
using std::out_of_range;

String::String()
    : length(0), str(nullptr){}

//todo test if it works with length == 1
String::String(const char _char)
    : length(1), str(new char[2])
{
    str[0] = _char; str[1] = '\0';
}

String::String(const char* other)
    : length(0), str(nullptr)
{
    copyOf(other);
}

String::String(const String& other)
    : length(0), str(nullptr)
{
    copyOf(other.c_string());
}

//implement swap idiom
String& String::operator=(const String& other)
{
    if (this != &other)
    {
        cleanUp();
        copyOf(other.c_string());
    }
    return *this;
}

String::String(String&& other) noexcept
{
    this->str = other.str;
    this->length = other.length;
    other.str = nullptr;
    other.length = 0;
}

String& String::operator=(String&& other) noexcept
{
    if (this != &other)
    {
        cleanUp();
        this->str = other.str;
        this->length = other.length;
        other.str = nullptr;
        other.length = 0;
    }

    return *this;
}

String::~String()
{
    cleanUp();
}


const char& String::operator[](const int i) const
{
    if ( i < 0 || i >= length)
        throw out_of_range("Out of bounds!");
    
    return this->c_string()[i];
}

char& String::operator[](int i)
{
    if (i < 0 || i >= length)
        throw out_of_range("Out of bounds!");
    
    return this->c_string()[i];
}

String String::operator+(const String& other) const
{
    const auto totalLength = length + other.length;
    char* buffer = new char[totalLength + 1];

    std::copy(str, str + length, buffer);
    std::copy(other.str, other.str + other.length, buffer + length);
    buffer[totalLength] = '\0';

    return String(buffer);
}

bool String::operator==(const String& other) const
{
    if (other.c_string() == nullptr) return false;
    return strcmp(str, other.str) == 0;
}


String& String::operator+=(const String& _other)
{
    if (this != &_other)
    {
        auto totalLength = length + _other.length;
        char* buffer = new char[totalLength + 1];

        std::copy(str, str + length, buffer);
        std::copy(_other.str, _other.str + _other.length, buffer + length);
        buffer[totalLength] = '\0';

        std::swap(str, buffer);
        length = totalLength;

        delete[] buffer;
    }

    return *this;
}

//MyString MyString::operator + (const MyString& other)
//{
//    size_t targetLength = this->length + other.length;
//    char* str = new char[targetLength + 1];
//    memcpy(str, this->str, this->length);
//    memcpy(str + this->length, other.str, other.length + 1);
//    return MyString(str);
//}

String String::operator+(const char* _other) const
{
    const auto charLength = strlen(_other);
    const auto totalLength = length + charLength;
    char* buffer = new char[totalLength];

    std::copy(str, str + length, buffer);
    std::copy(_other, _other + charLength, buffer + length);
    buffer[totalLength] = '\0';

    return String(buffer);
}


void String::copyOf(const char* other)
{
    
    if (other != nullptr)
    {
        length = strlen(other) + 1;
        str = new char[length];
        std::copy(other, other + length, str);
    }
}

ostream& operator<<(std::ostream& _os, const String& _string)
{
    _os << _string.c_string();
    return _os;
}

// use foreach loop
String String::toLowerCase() const
{
    String buffer = *this;

    for (int i = 0; i < length; i++) {
        buffer[i] = tolower(buffer[i]);
    }

    return buffer;
}

// use foreach loop
String String::toUpperCase() const
{
    String buffer = *this;

    for (int i = 0; i < length; i++) {
        buffer[i] = tolower(buffer[i]);
    }

    return buffer;
}

size_t String::getLength() const
{
    return length;
}

char* String::c_string() const
{
    return str;
}

String::operator const char* () const
{
    return str;
}

//todo check for safety
const char* String::begin()
{
    return &this->c_string()[0];
}

//todo check for safety
const char* String::end()
{
    return &this->c_string()[length];
}

void String::copyOf(const char* other)
{
    if (other != nullptr)
    {
        length = strlen(other) + 1;
        str = new char[length];
        std::copy(other, other + length, str);
    }
}

void String::cleanUp()
{
    if (this->str != nullptr)
    {
        delete[] str;
    }

    length = 0;
    str = nullptr;
}


