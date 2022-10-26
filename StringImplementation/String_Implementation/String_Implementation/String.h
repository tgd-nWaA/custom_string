#pragma once
#include <ostream>

class String
{
public:
    String(void);
    String(const char);
    String(const char*);

    explicit String(const std::string&); // is constructor necessary? is explicit necessary?

    String(const String&);  
    //copy-and-swap idiom implemented
    String& operator=(String other) &;
    String(String&&) noexcept; 

    ~String();

    const char& operator[](const size_t) const;
    char& operator[](const size_t);
    
    String& operator+=(const String&) &; // is it appropriate to make l-value ref-qualified here?

    String toLowerCase() const;
    String toUpperCase() const;

    //todo check for safety
    inline const char* begin()
    {
        return &this->getC_string()[0];
    };

    //todo check for safety
    inline const char* end()
    {
        return &this->getC_string()[length + 1];
    };

    inline size_t getLength() const
    {
        return length;
    };

    inline const char* getC_string() const
    {
        return str;
    };

    explicit inline operator const char* () const
    {
        return getC_string();
    };

    explicit inline operator std::string() const
    {
        return std::string(getC_string());
    };

private:

    //for copy-and-swap idiom implementation
    void swap(String&, String&);
    // deallocating memory and setting pointer and length to 0
    void cleanUp();

    size_t length;
    char* str;
};

std::ostream& operator<<(std::ostream& _os, const String& _string);

const String operator+(String, const String&);

inline bool operator == (const String& lstr, const String& rstr) noexcept
{
    return strcmp(lstr.getC_string(), rstr.getC_string()) == 0;
};
inline bool operator != (const String& lstr, const String& rstr) noexcept
{
    return strcmp(lstr.getC_string(), rstr.getC_string()) != 0;
};
inline bool operator >= (const String& lstr, const String& rstr) noexcept 
{
    return strcmp(lstr.getC_string(), rstr.getC_string()) >= 0;
};
bool operator <= (const String& lstr, const String& rstr) noexcept 
{
    return strcmp(lstr.getC_string(), rstr.getC_string()) <= 0;
};
bool operator >  (const String& lstr, const String& rstr) noexcept
{
    return strcmp(lstr.getC_string(), rstr.getC_string()) > 0;
};
bool operator <  (const String& lstr, const String& rstr) noexcept
{
    return strcmp(lstr.getC_string(), rstr.getC_string()) < 0;
};

