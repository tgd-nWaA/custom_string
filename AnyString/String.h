#pragma once
#include <ostream>
#include <string>
#include <memory>


template <typename CharT, typename Traits = std::char_traits<CharT>>
class String
{
public:

    String(void);
    String(const char);
    String(const char*);
    String(const std::string&);

    String(const String&);

    //String(const String&);
    ////copy-and-swap idiom implemented
    //String& operator=(String other)&;
    //String(String&&) noexcept;

    ~String(void);

    String& operator=(const String&);

    size_t len() const;
    bool empty() const;

    //support proxy group
    void check(size_t idx) const;
    void read(size_t idx) const;
    void write(size_t idx, char);

    Proxy operator[](size_t idx);
    const char& operator[](size_t) const;


    //String toLowerCase() const;
    //String toUpperCase() const;
    //inline const char* begin() const;
    //inline const char* end() const;
    //explicit inline operator const char* () const;
    //explicit inline operator std::string() const;
    
private:

    struct StringRep;

    std::shared_ptr<StringRep> rep;

    //StringRep* rep;

    class Proxy;
};

//std::ostream& operator<<(std::ostream& _os, const String& _string);
//
//const String operator+(String, const String&);
//
//inline bool operator == (const String& lstr, const String& rstr) noexcept
//inline bool operator != (const String& lstr, const String& rstr) noexcept
//inline bool operator >= (const String& lstr, const String& rstr) noexcept
//inline bool operator <= (const String& lstr, const String& rstr) noexcept
//inline bool operator >  (const String& lstr, const String& rstr) noexcept
//inline bool operator <  (const String& lstr, const String& rstr) noexcept





