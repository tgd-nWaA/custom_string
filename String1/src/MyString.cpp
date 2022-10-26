// MyString.cpp : Defines the entry point for the application.
//

#include "MyString.h"

using namespace std;

MyString::MyString(const char* other) :str(nullptr), length(0)
{
	copyOther(other);
}

MyString::MyString(const MyString& other):str(nullptr), length(0)
{
	copyOther(other.str);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		cleanUp();
		copyOther(other.str);
	}

	return *this;
}

MyString::MyString(MyString&& other) noexcept
{
	this->str = other.str;
	this->length = other.length;
	other.str = nullptr;
	other.length = 0;
}

MyString& MyString::operator=(MyString&& other) noexcept
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

MyString MyString::operator + (const MyString& other)
{
	size_t targetLength = this->length + other.length;
	char* str = new char[targetLength + 1];
	memcpy(str,  this->str, this->length);
    memcpy(str+this->length,  other.str, other.length+1);
	return MyString(str);
}

MyString::~MyString()
{
	cleanUp();
}

size_t MyString::Length() const
{
	return length;
}

const char* MyString::c_str() const
{
	return str;
}

void MyString::copyOther(const char* other)
{
	if (other != nullptr)
	{
        length = strlen(other);
        str = new char[length+1];
        memcpy(str, other, length+1);
	}
}

void MyString::cleanUp()
{
	if (this->str != nullptr)
	{
		delete[] str;
	}

	length = 0;
	str = nullptr;
}
