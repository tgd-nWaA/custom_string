
#define NDEBUG

#include <string>

#include "proxy.h"

template <typename CharT, typename Traits = std::char_traits<CharT>>
class m_basic_string {
public:

    //default constructor
    m_basic_string()
        : rep_(new string_rep(""))
    { 
        #ifndef NDEBUG
        std::cout << "default constructor"
        #endif
    };

    //default constructor
    m_basic_string(const CharT c)
        : rep_(new string_rep(c))
    {
        #ifndef NDEBUG
        std::cout << "converting constructor for one symbol of CharT "
        #endif
    };

    //converting constructor for c-style strings 
    m_basic_string(const CharT* s)
        : rep_(new string_rep(s))
    {
        #ifndef NDEBUG
        std::cout << "converting constructor for c-style strings "
        #endif
    };

    //converting constructor for std::basic_string<CharT>
    m_basic_string(std::basic_string<CharT>& s)
        : m_basic_string(s.c_str())
    {
        #ifndef NDEBUG
        std::cout << "converting constructor for std::basic_string<CharT>"
        #endif  
    };

    //copy constructor
    m_basic_string(const m_basic_string& c)
        : m_basic_string()
    {
        
        rep_ = c.rep_->get_copy();
        #ifndef NDEBUG
        std::cout << "copy constructor"
        #endif  
    };

    m_basic_string& operator=(m_basic_string& s) &
    {
        ++s.rep_->use_count_;

        if (--rep_->use_count_ == 0)
            delete rep_;

        rep_ = s.rep_;

        return *this;
    };

    m_basic_string(m_basic_string&& s) noexcept
        : m_basic_string()
    {
        std::swap(rep_, s.rep_);
    }

    m_basic_string& operator=(m_basic_string&& s) noexcept
    {
        ++s.rep_->use_count_;

        if (--rep_->use_count_ == 0)
            delete rep_;

        rep_ = s.rep_;

        return *this;
    }

    ~m_basic_string()
    {
        /*clear();*/
        
        if (--rep_->use_count_ == 0) {
            delete rep_;
        }

        #ifndef NDEBUG
        std::cout << "destructor"
        #endif  
    };

    m_basic_string& operator+=(const m_basic_string& s) & 
    {        
        
        size_t curr_len = len();
        size_t add_len = s.len();
        size_t total_len = curr_len + add_len;

        CharT* s_res = new CharT[total_len + 1];
        Traits::copy(s_res, rep_->str_, curr_len);
        Traits::copy(s_res + curr_len, s.rep_->str_, add_len + 1);

        string_rep* res(new string_rep(s_res));

        if (--rep_->use_count_ == 0)
            delete rep_;

        rep_ = res;

        return *this;
    };

    /*void clear(){};*/

    size_t len() const
    {
        return rep_->len();
    };

    const CharT* c_str() const
    {
        return rep_->c_str();
    };

    bool empty() const
    {
        return rep_->len() == 0;
    };

    explicit inline operator const char* () const
    {
        return c_str();
    };

    explicit inline operator 
        std::basic_string<CharT>() const
    {
        return std::basic_string<CharT>(c_str());
    };

    //todo correct?
    proxy<CharT> operator[](size_t i)
    {
        return proxy(rep_, i);
    };

    CharT operator[](size_t i) const
    {
        if (i > len())
            throw bad_index();

        return *(rep_ + i);
    };

    /*inline const char* begin() const
    {
        return &this->c_str()[0];
    };

    inline const char* end() const
    {
        return &this->c_str()[length + 1];
    };*/

private:

    /*void swap_with(m_basic_string& r)
    {
        std::swap(rep_, r.rep_);
    };*/

    class string_rep;
    class proxy;

    string_rep* rep_;
};

//template <typename CharT, typename Traits = std::char_traits<CharT>>
//std::basic_ostream<CharT>&
//operator<<(std::basic_ostream<CharT>& os, const proxy<CharT>& proxy)
//{
//    return os << str.c_str();
//};

template <typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_ostream<CharT>&
    operator<<(std::basic_ostream<CharT>& os, const m_basic_string<CharT>& str)
{
    return os << str.c_str();
};

template <typename CharT, typename Traits = std::char_traits<CharT>>
m_basic_string<CharT> operator+(m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return l += r;
};

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator==(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return (Traits::compare(l.c_str(), r.c_str(), l.len()) == 0);
};

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator!=(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return !(l == (r));
};

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator<(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return (Traits::compare(l.c_str(), r.c_str(), l.len()) < 0);
};

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator>(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return !(l < r);
};

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator<=(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return l < r || l == r;
};

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator>=(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return !(l < r) || l == r;
};

template <typename T, typename S>
void swap_with(m_basic_string<T, S>& l, m_basic_string<T, S>& r)
{
    l.swap_with(r);
}

using m_string    = m_basic_string<char>;
using wm_string   = m_basic_string<wchar_t>;
using u16m_string = m_basic_string<char16_t>;
using u32m_string = m_basic_string<char32_t>;
