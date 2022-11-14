
#include <memory>

    struct bad_index : std::exception { };
    template <typename, typename> class m_basic_string;

    template <typename T, typename S>
    bool operator==(const T* l, const m_basic_string<T, S>& r)
    {
        return (r == l);
    }

    template <typename T, typename S>
    bool operator<(const T* l, const m_basic_string<T, S>& r)
    {
        return (!(r < l) && !(r == l));
    }

    template <typename T, typename S>
    bool operator!=(const T* l, const m_basic_string<T, S>& r)
    {
        return r != l;
    }

    template <typename T, typename S>
    const m_basic_string<T, S> operator+(const T* l, const m_basic_string<T, S>& r)
    {
        return r.addFromLeftStar(l);
    }

    template <typename T, typename S>
    const m_basic_string<T, S> operator+(const T l, const m_basic_string<T, S>& r)
    {
        return r.addFromLeft(l);
    }

    template <typename T, typename S>
    void swap(m_basic_string<T, S>& l, m_basic_string<T, S>& r)
    {
        l.swap(r);
    }

    template <typename T>
    struct array_deleter {
        void operator() (T const* p)
        {
            delete[] p;
        }
    };

    template <typename CharT, typename Traits = std::char_traits<CharT>>
    class m_basic_string {
    public:

        m_basic_string(m_basic_string const& c)
            : data_(c.data_)
            , len_(c.len_)
        { }

        m_basic_string()
            : data_(std::shared_ptr<CharT>(new CharT()))
            , len_(0)
        { }

        /*m_basic_string(CharT const* c)
        {
            len_ = Traits::length(c);
            data_ = std::shared_ptr<CharT>(new CharT[len_ + 1], array_deleter<CharT>());
            Traits::copy(data_.get(), c, len_ + 1);
        }*/

        /*m_basic_string(CharT const* c)
            : len_(Traits::length(c))
            , data_(std::shared_ptr<CharT>(new CharT[len_ + 1], array_deleter<CharT>()))
        {
             Traits::copy(data_.get(), c, len_ + 1);
        }*/

        /*m_basic_string(CharT const* c)
            : len_(Traits::length(c))
            , data_(std::shared_ptr<CharT>(new CharT[len_ + 1]))
        {
            Traits::copy(data_.get(), c, len_ + 1);
        }*/

        m_basic_string(CharT const* c)
            : len_(Traits::length(c))
        {
            data_ = std::shared_ptr<CharT>(new CharT[len_ + 1], array_deleter<CharT>());
            Traits::copy(data_.get(), c, len_ + 1);
        }

        /*m_basic_string(CharT const* c)
            : len_(Traits::length(c))
        {
            data_ = std::shared_ptr<CharT>(new CharT[len_ + 1]);
            Traits::copy(data_.get(), c, len_ + 1);
        }*/

        ~m_basic_string()
        {
            clear();
        }

        friend std::basic_ostream<CharT, Traits>&
            operator<<(std::basic_ostream<CharT, Traits>& os, const m_basic_string<CharT>& str) {
            return os << str.data_.get();
        }

        size_t len() const
        {
            return len_;
        }

        bool operator==(const m_basic_string& str) const
        {
            if (str.len() != len())
                return false;
            if (str.data_ == data_)
                return true;
            return (Traits::compare(data_.get(), str.data_.get(), str.len()) == 0);
        }

        bool operator==(const CharT* str) const
        {
            if (Traits::length(str) != len())
                return false;
            else
                return (Traits::compare(data_.get(), str, len()) == 0);
        }

        bool operator<(const m_basic_string& str) const
        {
            size_t r = str.len();
            if (r <= len())
                return (Traits::compare(data_.get(), str.data_.get(), r) < 0);
            else
                return (Traits::compare(data_.get(), str.data_.get(), len()) <= 0);
        }

        bool operator<(const CharT* str) const
        {
            size_t r = Traits::length(str);
            if (r <= len())
                return (Traits::compare(data_.get(), str, r) < 0);
            else
                return (Traits::compare(data_.get(), str, len()) <= 0);
        }

        bool operator!=(const m_basic_string& str) const
        {
            return !operator==(str);
        }

        bool operator!=(const CharT* str) const
        {
            return !operator==(str);
        }

        void clear()
        {
            data_ = std::shared_ptr<CharT>(new Char());
            len_ = 0;
        }

        void swap(m_basic_string& r)
        {
            std::swap(data_, r.data_);
            std::swap(len_, r.len_);
        }

        CharT const* c_str() const
        {
            return data_.get();
        }

        bool empty() const
        {
            return !len();
        }

        m_basic_string& operator=(m_basic_string const& c)
        {
            data_ = c.data_;
            len_ = c.len();
            return *this;
        }

        m_basic_string& operator=(const CharT* c)
        {
            size_t length = Traits::length(c);
            data_ = std::shared_ptr<CharT>(new CharT[length + 1], array_deleter<CharT>());
            len_ = length;
            Traits::copy(data_.get(), c, len_ + 1);
            return *this;
        }


        m_basic_string operator+(const CharT* s2) const
        {
            size_t length1 = len();
            size_t length2 = Traits::length(s2);
            size_t newLength = length1 + length2;
            std::shared_ptr<CharT> res(new CharT[newLength + 1], array_deleter<CharT>());
            Traits::copy(res.get(), data_.get(), length1);
            Traits::copy(res.get() + length1, s2, length2 + 1);
            m_basic_string result;
            result.data_ = res;
            result.len_ = newLength;
            return result;
        }

        m_basic_string operator+(const m_basic_string& s2) const
        {
            size_t length1 = len();
            size_t length2 = s2.len();
            size_t newLength = length1 + length2;
            std::shared_ptr<CharT> res(new CharT[newLength + 1], array_deleter<CharT>());
            Traits::copy(res.get(), data_.get(), length1);
            Traits::copy(res.get() + length1, s2.data_.get(), length2 + 1);
            m_basic_string result;
            result.data_ = res;
            result.len_ = newLength;
            return result;
        }

        m_basic_string operator+(const CharT s2) const
        {
            size_t length1 = len();
            size_t length2 = 1;
            size_t newLength = length1 + length2;
            std::shared_ptr<CharT> res(new CharT[newLength + 1], array_deleter<CharT>());
            Traits::copy(res.get(), data_.get(), length1);
            Traits::copy(res.get() + length1, &s2, length2);
            Traits::copy(res.get() + newLength, data_.get() + length1, 1);
            m_basic_string result;
            result.data_ = res;
            result.len_ = newLength;
            return result;
        }

        m_basic_string addFromLeftStar(const CharT* str) const
        {
            size_t currentLength = len();
            size_t lengthToAdd = Traits::length(str);
            size_t newLength = currentLength + lengthToAdd;
            std::shared_ptr<CharT> res(new CharT[newLength + 1], array_deleter<CharT>());
            Traits::copy(res.get(), str, lengthToAdd);
            Traits::copy(res.get() + lengthToAdd, data_.get(), currentLength + 1);
            m_basic_string result;
            result.data_ = res;
            result.len_ = newLength;
            return result;
        }

        m_basic_string addFromLeft(const CharT str) const
        {
            size_t length1 = len();
            size_t length2 = 1;
            size_t newLength = length1 + length2;
            std::shared_ptr<CharT> res(new CharT[newLength + 1], array_deleter<CharT>());
            Traits::copy(res.get(), &str, length2);
            Traits::copy(res.get() + length2, data_.get(), length1 + 1);
            m_basic_string result;
            result.data_ = res;
            result.len_ = newLength;
            return result;
        }

        m_basic_string& operator+=(const m_basic_string& str)
        {
            size_t currentLength = len();
            size_t lengthToAdd = str.len();
            size_t newLength = currentLength + lengthToAdd;
            std::shared_ptr<CharT> res(new CharT[newLength + 1], array_deleter<CharT>());
            Traits::copy(res.get(), data_.get(), currentLength);
            Traits::copy(res.get() + currentLength, str.data_.get(), lengthToAdd + 1);
            data_ = res;
            len_ = newLength;
            return *this;
        }

        m_basic_string& operator+=(const CharT* str)
        {
            size_t currentLength = len();
            size_t lengthToAdd = Traits::length(str);
            size_t newLength = currentLength + lengthToAdd;
            std::shared_ptr<CharT> res(new CharT[newLength + 1], array_deleter<CharT>());
            Traits::copy(res.get(), data_.get(), currentLength);
            Traits::copy(res.get() + currentLength, str, lengthToAdd + 1);
            data_ = res;
            len_ = newLength;
            return *this;
        }

        m_basic_string& operator+=(CharT const str)
        {
            size_t currentLength = len();
            size_t newLength = currentLength + 1;
            std::shared_ptr<CharT> res(new CharT[newLength + 1], array_deleter<CharT>());
            Traits::copy(res.get(), data_.get(), currentLength + 1);
            Traits::copy(res.get() + newLength, res.get() + currentLength, 1);
            Traits::copy(res.get() + currentLength, &str, 1);
            data_ = res;
            len_ = newLength;
            return *this;
        }


        class Proxy {
        public:
            Proxy(m_basic_string* str_ptr, size_t pos)
                : str_ptr_(str_ptr)
                , position_(pos)
            { }

            operator CharT()
            {
                if (position_ > str_ptr_->len())
                {
                    throw bad_index();
                }
                else
                    return *(str_ptr_->data_.get() + position_);
            }

            Proxy operator= (const CharT& value)
            {
                if (position_ > str_ptr_->len())
                {
                    throw bad_index();
                }
                if (str_ptr_->data_.use_count() == 1)
                {
                    *(str_ptr_->data_.get() + position_) = value;
                }
                if (str_ptr_->data_.use_count() != 1)
                {
                    size_t n = str_ptr_->len();
                    std::shared_ptr<CharT> res(new CharT[n + 1], array_deleter<CharT>());
                    Traits::copy(res.get(), str_ptr_->data_.get(), n + 1);
                    *(res.get() + position_) = value;
                    str_ptr_->data_ = res;
                }
                return *this;
            }

        private:
            m_basic_string* str_ptr_;
            size_t                  position_;
        };

        Proxy operator[](size_t i)
        {
            return Proxy(this, i);
        }

        CharT operator[](size_t i) const
        {
            if (i > len())
            {
                throw bad_index();
            }
            return *(data_.get() + i);
        }

    private:
        std::shared_ptr<CharT>  data_;
        size_t                  len_;
    };

    typedef m_basic_string<char>                     m_string;
    typedef m_basic_string<wchar_t>                  wm_string;
