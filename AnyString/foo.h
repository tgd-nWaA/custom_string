
#include <memory>
#include <string>

class bad_index : std::exception {};

template <typename CharT, typename Traits = std::char_traits<CharT>>
class m_basic_string {
public:

    //default constructor
    m_basic_string()
        : rep_(nullptr)
    {}

    //convering constructor for c-style strings
    m_basic_string(const CharT* s)
        : m_basic_string(s)
    {};

    //converting constructor for std::basic_string<CharT>
    m_basic_string(std::basic_string<CharT>& s)
        : rep_(s);
    {};

    //TODO how to get representation?
    //copy constructor
    m_basic_string(const m_basic_string& c)
        : rep_(c.get_rep())
    {};

    //copy-and-swap implemented 
    m_basic_string& operator=(m_basic_string other) &
    {
        swap(*this, other);

        return *this;
    }

    //move constructor
    m_basic_string (m_basic_string&& other) noexcept
        : m_basic_string()
    {
        swap(*this, other);
    }

    ~m_basic_string()
    {
        clear();
    }

    m_basic_string& operator+=(const m_basic_string& str)&
    {
        size_t curr_len = len();
        size_t add_len = str.len();
        size_t total_len = curr_len + add_len;

        rep_ = new CharT[total_len + 1];
        Traits::copy(res.get(), rep_.get(), curr_len);
        Traits::copy(res.get() + curr_len, str.rep_.get(), add_len + 1);

        rep_ = res;
        len_ = total_len;
        return *this;
    }

    void clear()
    {
        rep_.reset();
        len_ = 0;
    }

    size_t len() const
    {
        return len_;
    }

    const CharT* c_str() const
    {
        return rep_.get();
    }

    bool empty() const
    {
        return len() == 0;
    }

    proxy operator[](size_t i)
    {
        return proxy(this, i);
    }

    CharT operator[](size_t i) const
    {
        if (i > len())
            throw bad_index();
            
        return *(rep_.get() + i);
    }

private:

    /*void swap(m_basic_string& r)
    {
        std::swap(rep_, r.rep_);
        std::swap(len_, r.len_);
    }*/

    class string_rep;
    class proxy;

    string_rep* rep_;
};

template <typename CharT, typename Traits = std::char_traits<CharT>>
std::basic_ostream<CharT>&
    operator<<(std::basic_ostream<CharT>& os, const m_basic_string<CharT>& str)
{
    return os << str.c_str();
}

template <typename CharT, typename Traits = std::char_traits<CharT>>
m_basic_string<CharT> operator+(const m_basic_string<CharT> l, const m_basic_string<CharT>& r)
{
    return std::move(l += r);
}

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator==(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return (Traits::compare(l.c_str(), r.c_str(), l.len()) == 0);
}

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator!=(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return !(l == (r));
}

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator<(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return (Traits::compare(l.c_str(), r.c_str(), l.len()) < 0);
}

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator>(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return !(l<r);
}

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator<=(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return l < r || l==r;
}

template <typename CharT, typename Traits = std::char_traits<CharT>>
bool operator>=(const m_basic_string<CharT>& l, const m_basic_string<CharT>& r)
{
    return !(l < r) || l==r;
}

template <typename T, typename S>
void swap(m_basic_string<T, S>& l, m_basic_string<T, S>& r)
{
    l.swap(r);
}

using m_string    = m_basic_string<char>;
using wm_string   = m_basic_string<wchar_t>;
using u8m_string  = m_basic_string<char8_t>;
using u16m_string = m_basic_string<char16_t>;
using u32m_string = m_basic_string<char32_t>;
