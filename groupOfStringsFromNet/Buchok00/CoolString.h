#pragma once
#include <ostream>

using std::string;
// arrow operator overload todo:
class String
{
public:
  
    String();
    String(const char _char);
    String(const char* const _string);
    String(const std::string _string);

    String(const String& _string);

    String(String&& _string) noexcept;

    ~String();

    String& operator=(const String&);
    String& operator=(String&&) noexcept;

    String operator+(const String&) const; 

    String& operator+=(const String&);

    bool operator==(const String&) const;

    bool operator!=(const String&) const;

    bool operator<(const String&) const;

    bool operator>(const String&) const;

    bool operator<=(const String&) const;

    bool operator>=(const String&) const;

    char operator[](const int index) const; 
    char& operator[](const int index);

    char* toCharArr(const String& _string);
    string toString(const String& _string);

    friend std::ostream& operator<<(std::ostream& _os, const String& _string);

    String toLowerCase() const;
    String toUpperCase() const;

    inline size_t length() const;
    char* getChars() const;
private:
    unsigned int _length; // rename to _length todo
    char* _string;
};