#include <iostream>
#include <string> // unn

using namespace std;

class String
{

public:

	String();
	
	String(const String&);
	String(const string&);
 	String(const char*);

	~String();

	String& operator=(const string&);
	String& operator=(const String&);
	String& operator=(const char*);

	String& operator+=(const string&);
	String& operator+=(const String&);
	String& operator+=(const char*);

	char& operator[](size_t);

	bool empty() const;
	size_t length() const;

	void copyon(char*, const char*, size_t);

	bool operator==(const String&, const String&);
	bool operator!=(const String&, const String&);

	bool operator<(const String&, const String&);
	bool operator<=(const String&, const String&);
	bool operator>(const String&, const String&);
	bool operator>=(const String&, const String&);

	const String operator+(String&, const String&);
	const String operator-(String&, const String&); 

private:

	char* arr;
	size_t length;
};

ostream& operator<<(ostream&, const String&);