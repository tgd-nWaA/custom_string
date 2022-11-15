

#include <string>

class bad_index : std::exception {};
class bad_pointer : std::exception {};

template <typename CharT, typename Traits = std::char_traits<CharT>>
class string_rep;

template <typename CharT, typename Traits = std::char_traits<CharT>>
class proxy
{
public:

    proxy(string_rep<CharT>* rep, size_t pos)
        : rep_(rep)
        , pos_(pos)
    {};

    operator CharT()
    {
        if (pos_ > rep_->len())
            throw bad_index();

        return *(rep_ + pos_);
    };

    proxy operator= (const CharT& value)
    {
    //    if (pos_ > rep_->len())
    //        throw bad_index();

    //    if (rep_->use_count() == 1)
    //        *(rep_ + pos_) = value;

    //    if (rep_->use_count() != 1)
    //    {
    //        size_t l = rep_->len();
    //        string_rep* res = string_rep<CharT>(new CharT[l + 1]);

    //        Traits::copy(res, rep_->c_str(), l + 1);
    //        *(res + pos_) = value;

    //        //todo correct?
    //        delete rep_;

    //        rep_ = res;
    //    }
        return *this;
    }

private:
    string_rep<CharT, Traits>* rep_;
    size_t        pos_;
};



#include <string>

template <typename CharT, typename Traits>
class string_rep {

	template <typename CharT, typename Traits>
	friend class m_basic_string;

public:
	//default constructor
	string_rep(void)
		: len_(0)
		, str_(nullptr)
		, use_count_(1)
	{};

	string_rep(const CharT c)
		: len_(1)
		, str_(new CharT[2])
		, use_count_(1)
	{
		*str_ = c; *(str_ + 1) = '\0';
	};

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
		delete str_;
	};

	//pseudo-copying constructor
	string_rep* get_copy() {
		++use_count_;
		return this;
	};

	//pseudo-ajssignment
	/*void assign(size_t len, const CharT* s) {
		if (s == nullptr)
			throw bad_pointer();

		CharT* res = new CharT[len + 1];
		Traits::copy(res, s, len + 1);


		if (this->use_count_ == 1)
			delete this;
		else
			--this->use_count_;




		this(res);
	};*/

	string_rep(const string_rep* rep)
		: len_(rep->len())
		, str_(str_->c_str())
		, use_count_(++rep->use_count())
	{};

	string_rep(const string_rep&) = delete;
	string_rep& operator=(const string_rep&) = delete;

	inline size_t use_count() const
	{
		return use_count_;
	};

	inline size_t len() const
	{
		return len_;
	};

	inline const char* c_str() const
	{
		return str_;
	};

private:
	size_t len_;
	CharT* str_;
	size_t use_count_;
	/*bool shareable_;*/
};