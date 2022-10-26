#include "String.h"

String::String()
{
	length = 10;
	arr = new char[10];
}

String::String(const char* str)
{
	length = strlen(str);
	arr = (char*)str;
}

String::String(const string& str)
{
	arr = new char[str.length()];
	length = str.length();
	strcpy_s(arr, str.length() + 1, str.c_str());
}

String::String(const String& str)
{
	length = str.length();
	unsigned int i;
	arr = new char[length];
	for (i = 0; i < length; i++)
		arr[i] = str[i];
}

String::~String()
{
	delete[] arr;
}

String& String::operator=(const String& str)
{
	length = str.length();
	string temp = str.text();

	unsigned int i;
	arr = new char[length];
	for (i = 0; i < length; i++)
		arr[i] = temp[i];

	return *this;
}

const char& String::operator[](const unsigned int i) const
{
	if ((i < length) && (i >= 0))
		return arr[i];
	else
		throw arr;
}

String String::operator+(const String& str)
{
	string temp = arr; 
	temp += str.text();

	return String(temp);
}

String  String::operator+(const string& str) {
	string temp = str + arr;

	return String(temp);
}

String  String::operator+(const char* ch) {
	string temp = arr;

	unsigned int i;
	for (i = 0; i < strlen(ch); i++)
		temp += ch[i];

	return String(temp);
}

String& String::operator+=(const String& str)
{
	string temp = arr;
	temp += str.text();

	arr = new char[temp.length()];

	unsigned int i;
	for (i = 0; i < temp.length(); i++)
		arr[i] = temp[i];

	length = temp.length();
	

	return *this;
}

String& String::operator+=(const string& str) {
	string temp = arr;
	temp += str;

	length = temp.length();

	arr = new char[length];
	unsigned int i;
	for (i = 0; i < length; i++)
		arr[i] = temp[i];

	return *this;
}

String& String::operator+=(const char* ch) {
	string temp = arr;
	unsigned int i;
	for (i = 0; i < strlen(ch); i++)
		temp += ch[i];

	length = temp.length();

	arr = new char[temp.length() + 1];

	for (i = 0; i < temp.length() + 1; i++)
		arr[i] = temp[i];

	return *this;

}

bool String::operator==(const String& str)
{
	unsigned int strlen = str.length();
	const char* strchar = str.text();

	if (length != strlen) {
		return false;
	}
	unsigned int i;
	for (i = 0; i < strlen; i++) {
		if (arr[i] != strchar[i]) {
			return false;
		}
	}
	return true;
}

bool String::operator==(const string& str) {
	string temp(arr);
	return temp == str;
}

bool String::operator==(const char* ch) {
	return arr == ch;
}

bool String::operator!=(const String& str)
{
	unsigned int strlen = str.length();
	const char* strchar = str.text();

	if (length != strlen) {
		return true;
	}
	unsigned int i;
	for (i = 0; i < strlen; i++) {
		if (arr[i] != strchar[i]) {
			return true;
		}
	}
	return false;
}

bool String::operator!=(const string& str) {
	return !(*this == str);
}

bool String::operator!=(const char* ch) {
	return !(*this == ch);
}

bool operator<(const String& s1, const String& s2) {
	return s1.length() < s2.length();
}


bool operator>(const String& s1, const String& s2) {
	return s1.length() > s2.length();
}


bool operator<=(const String& s1, const String& s2) {
	return s1.length() < s2.length() || s1 == s2;
}


bool operator>=(const String& s1, const String& s2) {
	return s1.length() > s2.length() || s1 == s2
}

ostream& operator<<(ostream& os, const String& str)
{
	string rez;

	unsigned int i;
	for (i = 0; i < str.length(); i++) {
		rez += str[i];
	}
	
	os << "String: " << rez << endl;
	return os;
}
