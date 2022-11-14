
#define NDEBUG

#include <memory>
#include <string>

struct bad_index : std::exception {};

template <typename CharT, typename Traits = std::char_traits<CharT>>
class m_basic_string {
public:

    //default constructor
    m_basic_string()
        : data_(nullptr)
        , len_(0)
    {}

    //convering constructor for c-style strings
    m_basic_string(CharT const* c)
        : len_(Traits::length(c))
        , data_(nullptr)
    {
        data_ = std::shared_ptr<CharT>(new CharT[len_ + 1]);
        Traits::copy(data_.get(), c, len_ + 1);
    }

    //convering constructor for std::string
    m_basic_string(std::basic_string<CharT>& s)
        : len_(s.length())
        , data_(nullptr)
    {
        data_ = std::shared_ptr<CharT>(new CharT[len_ + 1]);
        Traits::copy(data_.get(), s.c_str(), len_ + 1);
    }

    //copy constructor
    m_basic_string(const m_basic_string& c)
        : data_(c.data_)
        , len_(c.len_)
    { }

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

        std::shared_ptr<CharT> res(new CharT[total_len + 1]);
        Traits::copy(res.get(), data_.get(), curr_len);
        Traits::copy(res.get() + curr_len, str.data_.get(), add_len + 1);

        data_ = res;
        len_ = total_len;
        return *this;
    }

    void clear()
    {
        data_.reset();
        len_ = 0;
    }

    size_t len() const
    {
        return len_;
    }

    const CharT* c_str() const
    {
        return data_.get();
    }

    bool empty() const
    {
        return len() == 0;
    }

    class Proxy 
    {
    public:
        Proxy(m_basic_string* str_ptr, size_t pos)
            : str_(str_ptr)
            , pos_(pos)
        {}

        operator CharT()
        {
            if (pos_ > str_->len())
            {
                throw bad_index();
            }
            else
                return *(str_->data_.get() + pos_);
        }

        Proxy operator= (const CharT& value)
        {
            if (pos_ > str_->len())
            {
                throw bad_index();
            }
            if (str_->data_.use_count() == 1)
            {
                *(str_->data_.get() + pos_) = value;
            }
            if (str_->data_.use_count() != 1)
            {
                size_t l = str_->len();
                std::shared_ptr<CharT> res(new CharT[l + 1]);
                Traits::copy(res.get(), str_->data_.get(), l + 1);
                *(res.get() + pos_) = value;
                str_->data_ = res;
            }
            return *this;
        }

    private:
        m_basic_string*   str_;
        size_t            pos_;
    };

    Proxy operator[](size_t i)
    {
        return Proxy(this, i);
    }

    CharT operator[](size_t i) const
    {
        if (i > len())
            throw bad_index();
            
        return *(data_.get() + i);
    }

private:

    void swap(m_basic_string& r)
    {
        std::swap(data_, r.data_);
        std::swap(len_, r.len_);
    }

    std::shared_ptr<CharT>  data_;
    size_t                  len_;
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
