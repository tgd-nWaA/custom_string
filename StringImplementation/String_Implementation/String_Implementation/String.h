#pragma once
#include <ostream>

class String
{
public:
    String(void);
    String(const char);
    String(const char*);

    String(const String&) ;

    //maybe we should make it private and not friend?
  

    String& operator=(String other);
    //String& operator=(const String&);

    String(String&&) noexcept; //why noexcept here?

    ~String();

    const char& operator[](const int) const;
    char& operator[](const int);
    
    String operator+(const String&) const;
    String& operator+=(const String&);

    String toLowerCase() const;
    String toUpperCase() const;

    void reset();

    const char* begin(); //should we have const here?
    const char* end(); // and here?

    //todo check for safety
    const char* String::begin()
    {
        return &this->c_string()[0];
    }

    //todo check for safety
    const char* String::end()
    {
        //[length + 1] as we assign in constructor length without accounting \0
        return &this->c_string()[length];
    }

    inline size_t getLength() const
    {
        return length;
    }

    //how does it work?
    explicit inline operator const char* () const
    {
        return str;
    }

private:

    //for copy-and-swap idiom implementation
    void swap(String&, String&);
    // deallocating memory and setting pointer and length to 0
    void cleanUp();

    size_t length;
    char* str;
};


bool operator == (const String& lstr, const String& rstr);
bool operator != (const String& lstr, const String& rstr);
bool operator >= (const String& lstr, const String& rstr);
bool operator <= (const String& lstr, const String& rstr);
bool operator >  (const String& lstr, const String& rstr);
bool operator <  (const String& lstr, const String& rstr);

std::ostream& operator<<(std::ostream& _os, const String& _string);