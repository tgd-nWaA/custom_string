
#define NDEBUG

#include <string>

class bad_index : std::exception {};
class bad_pointer : std::exception {};

template <typename CharT, typename Traits = std::char_traits<CharT>>
class m_basic_string {
public:

	//template <typename CharT, typename Traits = std::char_traits<CharT>>
	class string_rep {

		friend class m_basic_string;

	public:
		string_rep(void);
		string_rep(const CharT c);
		string_rep(const CharT* s);
		/*string_rep(std::string&);*/

		~string_rep();

		//pseudo-copying constructor
		/*string_rep* get_copy();*/
		string_rep* get_copy();

		string_rep(const string_rep&) = delete;
		string_rep& operator=(const string_rep&) = delete;

		inline size_t use_count() const
		{return use_count_;};

		inline size_t len() const
		{return len_;};

		inline const char* c_str() const
		{return str_;};

	private:

		size_t len_;
		CharT* str_;
		size_t use_count_;
		/*bool shareable_;*/
	};


	//template <typename CharT, typename Traits = std::char_traits<CharT>>
	class proxy
	{
	public:

		proxy(string_rep* rep, size_t pos);

		inline operator CharT() const;

		inline ~proxy() {};

		proxy operator= (const CharT& value);

	private:
		string_rep* rep_;
		size_t             pos_;
	};

	//converting
	m_basic_string(void);
	m_basic_string(const CharT c);
	m_basic_string(const CharT* s);
	m_basic_string(std::basic_string<CharT>& s);

	//copy
	m_basic_string(const m_basic_string& c);
	m_basic_string& operator=(m_basic_string& s)&;

	//move
	m_basic_string(m_basic_string&& s) noexcept;
	m_basic_string& operator=(m_basic_string&& s) noexcept;

	~m_basic_string();

	m_basic_string& operator+=(const m_basic_string& s)&;

	//todo correct?
	proxy operator[](size_t i);

	CharT operator[](size_t i) const;

	inline size_t len() const
	{
		return rep_->len();
	};

	inline const CharT* c_str() const
	{
		return rep_->c_str();
	};

	inline bool empty() const
	{
		return rep_->len() == 0;
	};

	//explicit inline operator const char* () const
	//{
	//	return c_str();
	//};

	//explicit inline operator
	//	std::basic_string<CharT>() const
	//{
	//	return std::basic_string<CharT>(c_str());
	//};

	/*inline const char* begin() const
	{
		return &this->c_str()[0];
	};

	inline const char* end() const
	{
		return &this->c_str()[length + 1];
	};*/

private:
	
	string_rep* rep_;
};

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

using m_string = m_basic_string<char>;
using wm_string = m_basic_string<wchar_t>;
using u16m_string = m_basic_string<char16_t>;
using u32m_string = m_basic_string<char32_t>;


//default constructor
template <typename CharT, typename Traits>
m_basic_string<CharT, Traits>::m_basic_string(void)
	: rep_(new string_rep(""))
{
	#ifndef NDEBUG
	std::cout << "default constructor"
	#endif
};

//converting constructor for CharT
template <typename CharT, typename Traits>
m_basic_string<CharT, Traits>::m_basic_string(const CharT c)
	: rep_(new string_rep())
{
	#ifndef NDEBUG
	std::cout << "converting constructor for CharT"
	#endif
};

//converting constructor for CharT
template <typename CharT, typename Traits>
m_basic_string<CharT, Traits>::~m_basic_string()
{
	if (--rep_->use_count_ == 0)
		delete rep_;

	#ifndef NDEBUG
	std::cout << "destructor"
	#endif  
};

//converting constructor for c-style strings 
template <typename CharT, typename Traits>
m_basic_string<CharT, Traits>::m_basic_string(const CharT* s)
	: rep_(new string_rep(s))
{
	#ifndef NDEBUG
	std::cout << "converting constructor for c-style strings "
	#endif  
};

//converting constructor for std::basic_string<CharT>
template <typename CharT, typename Traits>
m_basic_string<CharT, Traits>::
m_basic_string(std::basic_string<CharT>& s)
	: m_basic_string(s.c_str())
{
	#ifndef NDEBUG
	std::cout << "converting constructor for std::basic_string<CharT>"
	#endif  
};

//TODO copy constructor
//template <typename CharT, typename Traits>
//m_basic_string<CharT, Traits>::
//m_basic_string(const m_basic_string& c)
//	: m_basic_string()
//{
//	rep_ = c.rep_->get_copy();
//	#ifndef NDEBUG
//	std::cout << "copy constructor"
//	#endif    
//};

//
//m_basic_string& operator=(m_basic_string& s)&
//{
//	++s.rep_->use_count_;
//
//	if (--rep_->use_count_ == 0)
//		delete rep_;
//
//	rep_ = s.rep_;
//
//	return *this;
//};

//
//m_basic_string(m_basic_string&& s) noexcept
//	: m_basic_string()
//{
//	std::swap(rep_, s.rep_);
//}
//
//m_basic_string& operator=(m_basic_string&& s) noexcept
//{
//	++s.rep_->use_count_;
//
//	if (--rep_->use_count_ == 0)
//		delete rep_;
//
//	rep_ = s.rep_;
//
//	return *this;
//}
//

//
//m_basic_string& operator+=(const m_basic_string& s)&
//{
//
//	size_t curr_len = len();
//	size_t add_len = s.len();
//	size_t total_len = curr_len + add_len;
//
//	CharT* s_res = new CharT[total_len + 1];
//	Traits::copy(s_res, rep_->str_, curr_len);
//	Traits::copy(s_res + curr_len, s.rep_->str_, add_len + 1);
//
//	string_rep* res(new string_rep(s_res));
//
//	if (--rep_->use_count_ == 0)
//		delete rep_;
//
//	rep_ = res;
//
//	return *this;
//};
//

//
////todo correct?
//proxy operator[](size_t i)
//{
//	return proxy(rep_, i);
//};
//
//CharT operator[](size_t i) const
//{
//	if (i > len())
//		throw bad_index();
//
//	return *(rep_ + i);
//};


//default constructor
template <typename CharT, typename Traits>
m_basic_string<CharT, Traits>::
string_rep::string_rep(void)
	: len_(0)
	, str_(nullptr)
	, use_count_(1)
{};

//converting constructor for CharT
template <typename CharT, typename Traits>
m_basic_string<CharT, Traits>::
string_rep::string_rep(const CharT c)
	: len_(1)
	, str_(new CharT[2])
	, use_count_(1)
{
	*str_ = c;
	*(str_ + 1) = '\0';
};

//converting constructor for c-style strings
template <typename CharT, typename Traits>
m_basic_string<CharT, Traits>::
string_rep::string_rep(const CharT* s)
	: len_(Traits::length(s))
	, str_(new CharT[len_ + 1])
	, use_count_(1)
{
	Traits::copy(str_, s, len_ + 1);
};

template <typename CharT, typename Traits>
m_basic_string<CharT, Traits>::
string_rep::~string_rep()
{
	delete str_;
};

//template <typename CharT, typename Traits>
//m_basic_string<CharT, Traits>::string_rep*
//m_basic_string<CharT, Traits>::
//string_rep::get_copy()
//{
//	++use_count_;
//	return this;
//};

template <typename CharT, typename Traits>
typename m_basic_string<CharT, Traits>::string_rep*
m_basic_string<CharT, Traits>::
string_rep::get_copy()
{
	++use_count_;
	return this;
};

//string_rep(const string_rep* rep)
//	: len_(rep->len())
//	, str_(str_->c_str())
//	, use_count_(++rep->use_count())
//{};


////pseudo-ajssignment
//template <typename CharT, typename Traits>
//void m_basic_string<CharT, Traits>::
//string_rep::assign(size_t len, const CharT* s)
//{
//	if (s == nullptr)
//		throw bad_pointer();
//
//	CharT* res = new CharT[len + 1];
//	Traits::copy(res, s, len + 1);
//
//
//	if (this->use_count_ == 1)
//		delete this;
//	else
//		--this->use_count_;
//
//	this(res);
//};



//proxy(string_rep* rep, size_t pos);
//
//inline operator CharT() const
//{
//	if (pos_ > rep_->len())
//		throw bad_index();
//
//	return *(rep_ + pos_);
//};
//
//~proxy();
//
//proxy operator= (const CharT& value);

template <typename CharT, typename Traits>
m_basic_string<CharT, Traits>::proxy::
proxy(string_rep* rep, size_t pos)
	: rep_(rep)
	, pos_(pos)
{};

template <typename CharT, typename Traits>
inline m_basic_string<CharT, Traits>::proxy::
operator CharT() const
{
	if (pos_ > rep_->len())
		throw bad_index();

	return *(rep_ + pos_);
};



template <typename CharT, typename Traits>
typename m_basic_string<CharT, Traits>::proxy
m_basic_string<CharT, Traits>::
proxy::operator=(const CharT& value)
{

	

	//if (pos_ > rep_->len())
		//    throw bad_index();

		//if (rep_->use_count() == 1)
		//    *(rep_ + pos_) = value;

		//if (rep_->use_count() != 1)
		//{
		//    size_t l = rep_->len();
		//    string_rep* res = string_rep<CharT>(new CharT[l + 1]);

		//    Traits::copy(res, rep_->c_str(), l + 1);
		//    *(res + pos_) = value;

		//    //todo correct?
		//    delete rep_;

		//    rep_ = res;
		//}
	return *this;
};

