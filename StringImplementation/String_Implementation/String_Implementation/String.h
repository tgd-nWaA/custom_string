#pragma once
#include <ostream>

class String
{
public:
    String(void);
    String(const char);
    String(const char*);

    String(const String&);
    String& operator=(const String&);

    String(String&&) noexcept; //why noexcept here?
    String& operator=(String&&) noexcept;

    ~String();

    operator const char* () const; //how does it work?

    const char& operator[](const int) const;
    char& operator[](const int);

    bool operator==(const String&) const;
    
    String& operator+=(const String&);
   
    String operator+(const String&) const;


    String toLowerCase() const;
    String toUpperCase() const;


    void reset();

    
    const char* begin(); //should we have const here?
    const char* end(); // and here?

    inline size_t getLength() const;
    inline char* c_string() const; //why we don't have const after char* and how to make const char* 

private:
    /*function used in converting
    and copying constructor and
    copying assignment operator*/
    void copyOf(const char*);
    void cleanUp();

    size_t length;
    char* str;
};

std::ostream& operator<<(std::ostream& _os, const String& _string);