#pragma once
#include <ostream>

using std::string;
//todo: arrow operator 
class String
{
public:
    String();
    String(const char);
    explicit String(const char* const _string);
    explicit String(const string& _string);

    //Copying Constructor
    String(const String& _string);

    //Moving constructor
    String(String&& _string) noexcept;

    ~String();

    //Copying assignment operator 
    String& operator=(const String&);
    //Moving assignment operator 
    String& operator=(String&&) noexcept;

    String operator+(const String&) const;

    String& operator+=(const String&);

    bool operator==(const String&) const;

    bool operator!=(const String&) const;

    bool operator<(const String&) const;

    bool operator>(const String&) const;

    bool operator<=(const String&) const;

    bool operator>=(const String&) const;

    char& operator[](const int index);

    //member functions for type conversion 
    char* toCharArr(const String& _string);
    string toString(const String& _string);
    
    //ostream operator 
    friend std::ostream& operator<<(std::ostream& os, const String& _string);

    String toLowerCase() const;
    String toUpperCase() const;

    inline size_t length() const;
    char* getChars() const;
private:
    unsigned int _length; 
    char* _string;

};

