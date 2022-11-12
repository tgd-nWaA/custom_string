#pragma once

#include <iostream>
#include <string>

using namespace std;

class String
{

private:

	char* arr;
	size_t length;

public:

	String();

	String(const String&);
	String(const string&);
	String(const char*);

	~String();

	String& operator=(const String&);

	String& operator+=(const string&);
	String& operator+=(const String&);
	String& operator+=(const char*);

	char& operator[](size_t);

	const unsigned int length() const { return len; }
	const char* text() const { return arr; }

	bool operator==(const String&, const String&);
	bool operator!=(const String&, const String&);

	bool operator<(const String&, const String&);
	bool operator<=(const String&, const String&);
	bool operator>(const String&, const String&);
	bool operator>=(const String&, const String&);

	const String operator+(String&, const String&);
	const String operator+(String&, const string&);
	const String operator+(String&, const char*);

};

ostream& operator<<(ostream&, const String&);