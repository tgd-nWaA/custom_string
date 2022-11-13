#include "String.h"

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>



struct String::StringRep {

    size_t len;
    char* alloc;
    size_t ref_counter;
    //bool shareable;

    StringRep(const char* s = "");
    StringRep(std::string&);

    ~StringRep();

    //pseudo-copying constructor
    StringRep* get_own_copy();
    
    //pseudo-ajssignment
    void assign(size_t len,const char*);

    StringRep(const StringRep&) = delete;
    StringRep& operator=(const StringRep&) = delete;

};

class Proxy {

    friend class String;

private:
    size_t idx;
    String& proxyship;
    Proxy(String&, size_t idx);

public:

    operator char() const;
    Proxy& operator=(char c);
};

String::StringRep*
String::StringRep::get_own_copy() {
    if (ref_counter == 1) 
        return this;
    ref_counter--;

    return new StringRep(len, alloc);
};

String::Proxy String::operator[](size_t idx) {
    check(i);

    return Proxy(*this, i);
};

void String::StringRep::
    assign(size_t len, const char* s) {
    if (s == nullptr) {
        //throw BadString("Not defined pointer") 
    }

    if (this->len != len) {
        delete alloc;
        this->len = len;

        //this->len or len ???
        alloc = new char[this->len + 1];
    }

    strcpy(alloc, s);
};

void String::write(size_t idx, char c) {
    rep = rep->get_own_copy();

    rep->alloc[i] = c;
}

String::StringRep::StringRep(const char* s)
    : 
    len(strlen(s)),
    alloc(new char[len + 1]),
    ref_counter(1),
    shareable(true)
{
     std::copy(s, s + len + 1, alloc);
};

String::String()
    : rep(new StringRep(""){};

String::String(const char* s)
    : rep(new StringRep(s)){};


String& String::operator=(const String& s) {
    s.rep->ref_counter++;

    if (--rep->ref_counter == 0)
        delete rep;

    rep = s.rep;
    return *this;
};

String::String(const String& s) {
    s.rep->ref_counter++;
    
    rep = s.rep;

};

String::~String() {
    if (rep->ref_counter == 0) {
        delete rep;
    }
};

char& String::operator[](size_t i) {
    if (rep->ref_counter > 1) {

        --rep->ref_counter;
        rep = new StringRep(rep->alloc);
    }

    rep->shareanble = false;
    return rep->alloc[i];
};

const char& String::operator[](size_t i) const {
    if (rep->len <= i) {
        return rep->alloc[i];
    }
};


String::Proxy::operator char() const {

    return proxyship.read(idx);
};

//String::Proxy& String::Proxy
//operator=(char c) {
//
//
//    proxyship.write(idx, c);
//    return *this;
//};
