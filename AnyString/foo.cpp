#include "foo.h"

template <typename CharT, typename Traits = std::char_traits<CharT>>
class string_rep {
public:

    //default constructor
    string_rep(void)
        : len_(0)
        , str_(nullptr)
        , use_count_(1)
    {};

    /*string_rep(const CharT c) {

    };*/

    //converting constructor for c-style strings
    string_rep(const CharT* s)
        : len_(Traits::length(s))
        , str_(new CharT[len_ + 1])
        , use_count_(1)
    {
        Traits::copy(str_, s, len_ + 1);
    };

    /*string_rep(std::string&);*/

    ~string_rep() {
        if (use_count_ == 1) {
            delete str_;
        }
    };

    //pseudo-copying constructor
    string_rep* get_own_copy();

    //pseudo-ajssignmentp
    void assign(size_t len, const char*);

    string_rep(const string_rep&) = delete;
    string_rep& operator=(const string_rep&) = delete;

private:
    size_t len_;
    CharT* str_;
    size_t use_count_;
    /*bool shareable_;*/
};

template <typename CharT, typename Traits = std::char_traits<CharT>>
class proxy
{
public:
    proxy(m_basic_string* str_ptr, size_t pos)
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

    proxy operator= (const CharT& value)
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