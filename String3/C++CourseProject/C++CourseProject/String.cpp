#include "String.h"
#include <string> //Only used for std::exception

String::String(void)
{
	m_String = new char[1];
	m_String[0] = '\0';
}

String::String(const char * str)
{
	m_String = StringCopy(str);
}


String::String(const String & otherString)
{
	m_String = StringCopy(otherString.m_String);
}

char* String::begin()
{
	return &m_String[0];
}

char* String::end()
{
	int endIdx =  StringLength(m_String);
	return &m_String[endIdx];
}

String::~String(void)
{
	delete [] m_String;
}

char& String::operator[](int index)
{
	if (index < 0 || index >= StringLength(m_String))
		throw std::exception("Index out of bounds");

	return m_String[index];
}

bool String::operator==(const char * inputString)
{
	return StringsAreEqual(m_String, inputString);
}

bool String::operator==(const String &inputString)
{
	return StringsAreEqual(m_String, inputString.m_String);
}

bool String::operator!=(const String &inputString)
{
	return !(m_String == inputString.m_String);
}

String& String::operator=(const String & OtherString)
{
	m_String = StringCopy(OtherString.m_String);

	return *this;
}

String& String::operator=(const char * InputString)
{
	m_String = StringCopy(InputString);

	return *this;
}

String String::operator+=(const String& other)
{
	int newLength = other.length() + this->length() + 1;
	char* temp = new char[newLength];
	int i;
	for (i = 0; i < this->length(); i++)
	{
		temp[i] = m_String[i];
	}

	for (int j = 0; j < other.length(); j++)
	{
		temp[i + j] = other.m_String[j];
	}

	temp[newLength - 1] = '\0';

	delete [] m_String;
	m_String = temp;

	return *this;
}


int String::length() const
{
	return StringLength(m_String);
}

String& String::insert(int pos, const String& other)
{

	if (pos < 0)
	{
		throw std::exception("Index out of bounds");
	}

	if (this->length() < pos)
	{
		pos = this->length();
	}

	int newLength = this->length() + other.length();
	char* temp = new char[newLength + 1];
	int i;
	int k = 0;
	for (i = 0; i < pos; i++)
	{
		temp[i] = m_String[k];
		k++;
	}

	for (int j = 0; j < other.length(); j++)
	{
		temp[i] = other.m_String[j];
		i++;
	}

	for (; i < newLength; i++)
	{
		temp[i] = m_String[k];
		k++;
	}

	temp[i] = '\0';

	delete[] m_String;
	m_String = temp;

	return *this;
}
void String::push_back(char c)
{
	char* temp = new char[this->length() + 1 + 1]; //One for null terminator, one for new character
	int i;
	for (i = 0; i < this->length(); i++)
	{
		temp[i] = m_String[i];
	}

	temp[i] = c;
	temp[i + 1] = '\0';

	delete[] m_String;
	m_String = temp;
}
void String::pop_back()
{
	m_String[length() - 1] = '\0';
	char* temp = StringCopy(m_String);
	delete[] m_String;
	m_String = temp;
}
String& String::erase(int start, int count)
{
	if (start > length() || start < 0)
	{
		throw std::exception("Start index out of bounds");
	}
	if (start + count > length())
	{
		count = length() - start;
	}
	m_String[start] = '\0';
	char* temp = StringCopy(m_String);
	char* temp2 = StringCopy(&m_String[start + count]);
	String newString = temp;
	newString += temp2;

	m_String = StringCopy(newString.m_String);

	delete[] temp;
	delete[] temp2;

	return *this;
}



void String::Swap(String * A, String * B)
{
	String temporary = *A;

	*B = StringCopy(A->m_String);
	*A = temporary;
}

char * String::StringCopy(const char * B)
{
	int length = StringLength(B) + 1;

	char * a = new char[length];

	for(int i = 0; i < length; i++)
	{
		a[i] = B[i];
	}

	return a;
}


int String::StringLength(const char * InputString)
{
	int i = 0;
	while(InputString[i] != 0)
	{
		i++;
	}
	return i;
}

bool String::StringsAreEqual(const char * a , const char * b)
{
	int i;
	for(i = 0; a[i] != 0 && b[i] != 0; i++)
	{
		if(a[i] != b[i])
			return false;
	}

	if(a[i] != b[i])
		return false;

	return true;
}

String operator+(const String& lhs, const String& rhs)
{
	String temp = lhs;
	temp += rhs;
	return temp;
}