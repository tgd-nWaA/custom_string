#pragma once
#include <ostream>

class String
{
public:
    String(void);
    String(const char);
    String(const char*);

    String(const std::string&); // is constructor necessary?

    String(const String&);  
    //copy-and-swap idiom implemented
    String& operator=(String other);
    String(String&&) noexcept; 

    ~String();

    const char& operator[](const size_t) const;
    char& operator[](const size_t);
    
    String& operator+=(const String&);

    String toLowerCase() const;
    String toUpperCase() const;

    //todo check for safety
    const char* begin()
    {
        return &this->getC_string()[0];
    }

    //todo check for safety
    const char* end()
    {
        //[length + 1] as we assign in constructor length without accounting \0
        return &this->getC_string()[length];
    }

    inline size_t getLength() const
    {
        return length;
    }

    inline const char* getC_string() const
    {
        return str;
    }

    //how does it work?
    explicit inline operator const char* () const
    {
        return str;
    }

    explicit inline operator std::string() const
    {
        return std::string(str)
    }

private:

    //for copy-and-swap idiom implementation
    void swap(String&, String&);
    // deallocating memory and setting pointer and length to 0
    void cleanUp();

    size_t length;
    char* str;
};

std::ostream& operator<<(std::ostream& _os, const String& _string);

String operator+(const String&, const String&);

bool operator == (const String& lstr, const String& rstr);
bool operator != (const String& lstr, const String& rstr);
bool operator >= (const String& lstr, const String& rstr);
bool operator <= (const String& lstr, const String& rstr);
bool operator >  (const String& lstr, const String& rstr);
bool operator <  (const String& lstr, const String& rstr);

