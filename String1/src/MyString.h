// MyString.h : Include file for standard system include files,
// or project specific include files.

#ifndef MyString_H
#define MyString_H

#include <iostream>
#include<string.h>
// TODO: Reference additional headers your program requires here.


class MyString
{

public:
	MyString(const char* other);
	MyString() = default;

	MyString(const MyString& other);
	MyString& operator = (const MyString& other);

	MyString(MyString&& other) noexcept;
	MyString& operator = (MyString&& other) noexcept;

	MyString operator + (const MyString& other);

	char& operator [] (size_t pos);
	const char& operator [] (size_t pos) const;

	~MyString();
	size_t Length() const;
    const char* c_str() const;

private:
	void copyOther(const char* other);
	void cleanUp();
	char* str;
	size_t length;
};

#endif
