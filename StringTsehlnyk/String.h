/*
    Developed by Bohdan Tsehelnyk
*/
#pragma once

#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class String
{
public:
    // default
    String();

    // copy/move
    String(const String &str);
    String(String &&str);

    // converting
    String(const string &str);
    String(const char *str);

    // descturctor
    ~String();

    // copy/move operator
    String &operator=(const String &str);
    String &operator=(String &&str);

    // concatenate
    String &operator+=(const String &str);

    // multiply "ab" * 3 = "ababab"
    String &operator*=(const size_t n);

    // selector
    const char &operator[](size_t i) const;
    // modifier
    char &operator[](size_t i);

    // conversion functions
    explicit operator string() const;
    explicit operator const char *() const;

    // reserve space for string
    void reserve(size_t n);
    size_t capacity() const;

    size_t size() const;
    size_t length() const;

private:
    size_t _csize;
    char *_container;
    size_t _length;

    String(const char *str, size_t len);
    void _assign(const char *str, size_t len);
    void _assign(String &&str);
};

// comparision
bool operator<(const String &l, const String &r);
bool operator>(const String &l, const String &r);
bool operator<=(const String &l, const String &r);
bool operator>=(const String &l, const String &r);

bool operator==(const String &l, const String &r);
bool operator!=(const String &l, const String &r);

// concatenate
const String operator+(String l, const String &r);

// multiply "ab" * 3 = "ababab"
const String operator*(String str, const size_t n);
const String operator*(const size_t n, String str);

/*
    realization
*/
inline String::String() : _length(0), _csize(0), _container(nullptr)
{
    reserve(15);
}

inline String::String(const String &str) : String(str._container, str._length){}

inline String::String(const string &str) : String{str.c_str(), str.length()} {}

inline String::String(String &&str) : _length(0), _csize(0), _container(nullptr)
{
    _assign(forward<String>(str));
}

inline String::String(const char *str, size_t len) : _length(0), _csize(0), _container(nullptr)
{
    _assign(str, len);
}

inline String::String(const char *str) : _length(0), _csize(0), _container(nullptr)
{
    size_t len = 0;
    while (str[len] != '\0')
        ++len;
    _assign(str, len);
}

inline String::~String()
{
    delete[] _container;
    _container = nullptr;
    _length = 0;
    _csize = 0;
}

inline String &String::operator=(const String &str)
{
    _assign(str._container, str._length);
    return *this;
}

inline String &String::operator=(String &&str)
{
    _assign(forward<String>(str));
    return *this;
}

inline String &String::operator+=(const String &str)
{
    reserve(_length + str._length);
    for (size_t i = 0, j = _length; i < str._length + 1; ++i, ++j)
    {
        _container[j] = str._container[i];
    }
    _length += str._length;
    return *this;
}

String &String::operator*=(const size_t n)
{
    reserve(_length * n);
    for (int i = 1; i < n; ++i)
    {
        for (int j = i * _length, pos = 0; pos < _length; ++j, ++pos)
        {
            _container[j] = _container[pos];
        }
    }
    _length *= n;
    return *this;
}

inline const char &String::operator[](size_t i) const
{
    if (i > _length)
        throw std::out_of_range("out of range with index " + to_string(i) + " when actual size is " + to_string(_length));
    return _container[i];
}

inline char &String::operator[](size_t i)
{
    if (i > _length)
        throw std::out_of_range("out of range with index " + to_string(i) + " when actual size is " + to_string(_length));
    return _container[i];
}

inline String::operator string() const
{
    return string(_container);
}

inline String::operator const char *() const
{
    return _container;
}

 void String::reserve(size_t n)
{
    if (n <= _csize)
        return;
    size_t nsize = _csize * 2 > n ? _csize * 2 + 1 : n + 1;
    char *temp = new char[nsize];
    size_t i = 0;
    if (_container)
    {
        for (; i < _length; ++i)
        {
            temp[i] = _container[i];
        }
    }
    temp[i] = '\0';
    delete _container;
    _container = temp;
    _csize = nsize - 1;
}

size_t String::capacity() const
{
    return _csize;
}

size_t String::size() const
{
    return _length;
}

size_t String::length() const
{
    return size();
}

inline void String::_assign(const char *str, size_t len)
{
    if (len <= 0)
        reserve(15);
    else
        reserve(len);
    for (size_t i = 0; i < len + 1; ++i)
    {
        _container[i] = str[i];
    }
    _length = len;
}

inline void String::_assign(String &&str)
{
    delete[] _container;
    _container = str._container;
    str._container = nullptr;
    _csize = str._csize;
    str._csize = 0;
    _length = str._length;
    str._length = 0;
}

inline bool operator<(const String &l, const String &r)
{
    size_t i = 0;
    size_t j = 0;
    for (; i < l.length() && j < r.length(); ++i, ++j)
    {
        if (l[i] < r[j])
            return true;
    }
    if (i == l.length() && j != r.length())
        return true;
    return false;
}
inline bool operator>(const String &l, const String &r) { return r < l; }

inline bool operator<=(const String &l, const String &r) { return !(l > r); }

inline bool operator>=(const String &l, const String &r) { return !(l < r); }

inline bool operator==(const String &l, const String &r)
{
    if (l.length() != r.length())
        return false;
    for (int i = 0; i < l.length(); ++i)
    {
        if (l[i] != r[i])
            return false;
    }
    return true;
}

inline bool operator!=(const String &l, const String &r) { return !(l == r); }

inline const String operator+(String l, const String &r)
{
    l += r;
    return l;
}

inline const String operator*(String s, const size_t n)
{
    String str = s;
    str *= n;
    return str;
}

inline const String operator*(const size_t n, String str)
{
    str *= n;
    return str;
}

inline ostream &operator<<(ostream &out, const String &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        out << str[i];
    }
    return out;
}