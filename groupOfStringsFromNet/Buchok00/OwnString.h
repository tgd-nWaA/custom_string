#pragma once
#include <ostream>

class String
{
public:
    String();
    String(const char _char);
    String(const char* const _string);

    //Copy Constructor
    String(const String& _string);

    //Move Constructor
    String(String&& _string) noexcept;

    ~String();

    void reset();
    size_t length() const;
    char* asCString() const;

    //Cast to const char
    operator const char* () const;

    //Bracket Operator overloads
    char operator[](int _index) const;
    char& operator[](int _index);

    //Compare
    bool operator==(const String& _other) const;
    bool operator==(const char* _chars) const;

    //Copy Assignment Operator
    String& operator=(const String& _other);

    //Move Assignment Operator
    String& operator=(String&& _other) noexcept;

    //Add Operators
    String& operator+=(const String& _other);
    String& operator+=(const char* _other);
    String operator+(const String& _other) const;
    String operator+(const char* _other) const;

    //Stream Operator
    friend std::ostream& operator<<(std::ostream& _os, const String& _string);

    Vector<String> split(const char _delimiter);
    void replace(const char _target, const char _replacement);
    void removeCharacter(char _target);
    String toLowerCase() const;
private:
    unsigned int m_length;
    char* m_string;
};