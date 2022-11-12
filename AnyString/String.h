#pragma once
#include <ostream>
#include <string>

class String
{
public:

    String(void);
    String(const char);
    String(const char*);
    String(const std::string&);

    String(const String&);  
    //copy-and-swap idiom implemented
    String& operator=(String other) &;
    String(String&&) noexcept; 

    ~String();

    const char& operator[](const size_t) const;
    char& operator[](const size_t);

    String& operator+=(const String&) &;

    String toLowerCase() const;
    String toUpperCase() const;

    inline const char* begin() const 
    {
        return &this->c_str()[0];
    };

    inline const char* end() const
    {
        return &this->c_str()[length + 1];
    };

    inline size_t getLength() const
    {
        return length;
    };

    inline const char* c_str() const
    {
        return str;
    };

    explicit inline operator const char* () const
    {
        return c_str();
    };

    explicit inline operator std::string() const
    {
        return std::string(c_str());
    };

private:

    //for copy-and-swap idiom implementation
    void swap(String&, String&);
    // deallocating memory and setting pointer and length to 0
    void cleanUp();

    size_t length;
    char* str;
};

std::ostream& operator<<(std::ostream& _os,const String& _string);

const String operator+(String, const String&);

inline bool operator == (const String& lstr, const String& rstr) noexcept
{
    return strcmp(lstr.c_str(), rstr.c_str()) == 0;
};
inline bool operator != (const String& lstr, const String& rstr) noexcept
{
    return strcmp(lstr.c_str(), rstr.c_str()) != 0;
};
inline bool operator >= (const String& lstr, const String& rstr) noexcept 
{
    return strcmp(lstr.c_str(), rstr.c_str()) >= 0;
};
inline bool operator <= (const String& lstr, const String& rstr) noexcept 
{
    return strcmp(lstr.c_str(), rstr.c_str()) <= 0;
};
inline bool operator >  (const String& lstr, const String& rstr) noexcept
{
    return strcmp(lstr.c_str(), rstr.c_str()) > 0;
};
inline bool operator <  (const String& lstr, const String& rstr) noexcept
{
    return strcmp(lstr.c_str(), rstr.c_str()) < 0;
};

