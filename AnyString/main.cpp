

#include "m_string.h"

#include <iostream>
#include <sstream>

const char* res_is = "|>";
const wchar_t* wres_is = L"|>Result is: ";

size_t delim_count = 0;

std::ostream& highlight(std::ostream& os);
std::string delimeter(const char* str);

int main(void) {

	{		
		std::cout << delimeter("default ");
		m_string foo1;
		std::cout << res_is << foo1 << "\n";
	}
	
	{
		std::cout << delimeter("converting T ");
		m_string foo1('a');
		std::cout << res_is << foo1 << "\n";
	}

	{
		std::cout << delimeter("converting T* ");
		
		m_string foo1("Hallelujah");
		std::cout << res_is << foo1 << "\n";

		m_string  foo2("GOD");
		std::cout << res_is << foo2 << "\n";

		const m_string  foo3("Maria");
		std::cout << res_is << foo3 << "\n";

	}

	{
		std::cout << delimeter("converting std::string ");

		std::string foo1("Father");
		m_string foo2(foo1);
		std::cout << res_is << foo2 << "\n";
	}

	{
		std::cout << delimeter("operator=");

		m_string foo1("Cappuchino");
		m_string foo2("Latte");

		foo1 = foo2;
		std::cout << res_is << foo1 << "\n";

		foo1 = "Espreso";
		std::cout << res_is << foo1 << "\n";

		foo1 = 'a';
		std::cout << res_is << foo1 << "\n";
	}

	{
		std::cout << delimeter("operator +=");

		m_string foo1("Kratos says:");
		m_string foo2("\"ragnarok comes\"");

		std::cout << res_is << (foo1 += foo2) << "\n"; 
		std::cout << res_is << (foo1 += "hgfsjk") << "\n";
		std::cout << res_is << (foo1 += 'a') << "\n";
	}

	{
		std::cout << delimeter("operator +");

		m_string foo1("bob");
		m_string foo2(" loves cheeseburgers and women");

		std::cout << res_is << foo1 + foo2 << "\n";
		std::cout << res_is << foo1 + "PoP" << "\n";
		std::cout << res_is << foo1 + 'M' << "\n";
		std::cout << res_is << 'M' + foo1 << "\n";
		std::cout << res_is << "Music" + foo1 << "\n";
	}

	{
		std::cout << delimeter("operator[]");

		const m_string foo1("bob");
		m_string foo2("marli");

		std::cout << res_is << foo1[0] << "\n";
		std::cout << res_is << foo2[0] << "\n";
		foo2[0] = 'B';
		std::cout << res_is << foo2[0] << "\n";
	}

	{
		std::cout << delimeter("tolower, toupper");

		m_string foo1("BoB");

		std::cout << res_is << foo1.tolower() << "\n";
		std::cout << res_is << foo1.touppper() << "\n";
	}	

	{
		std::cout << delimeter("begin, end");

		m_string foo1("VISHEBABA");
		std::cout << res_is;

		for (char c : foo1) {
			std::cout << c;
		}

		std::cout << "\n";
	}

	{
		std::cout << delimeter("comparison operators");

		std::cout << std::boolalpha;

		m_string foo1("a");
		m_string foo2("b");

		std::cout << res_is << (foo1 == foo2) << "\n";
		std::cout << res_is << (foo1 != foo2) << "\n";
		std::cout << res_is << (foo1 >= foo2) << "\n";
		std::cout << res_is << (foo1 <= foo2) << "\n";
		std::cout << res_is << (foo1 > foo2) << "\n";
		std::cout << res_is << (foo1 < foo2) << "\n";

		foo1 == "hjfkdsk";
		"gfjkl" == foo1;

		foo1 != "hjfkdsk";
		"gfjkl" != foo1;

		foo1 < "hjfkdsk";
		"gfjkl" < foo1;

		foo1 > "hjfkdsk";
		"gfjkl" > foo1;

		foo1 <= "hjfkdsk";
		"gfjkl" <= foo1;

		foo1 >= "hjfkdsk";
		"gfjkl" >= foo1;

		std::cout << std::noboolalpha;
	}

	{
		std::cout << delimeter("Tra-ta-ta");
		m_string s("Tra-ta-ta");
		const char* ps = static_cast<const char*> (s);
		std::cout << res_is << (s += ps) << ';' << std::endl;
	}

	return 0;
}

std::string delimeter(const char* str) {
	std::stringstream ss;
	ss << "\n|> " << str << " <|\n|=" << highlight << "=| - - - - - - - - - - - - - - - - - - - - - |\n";
	   
	return ss.str();
}

std::ostream& highlight(std::ostream& os)
{
	static const char begin_sequence[]{ 0x1B,'[','\0' };

	static const char italics[]{ 0x1B,'[','3','m','\0'};
	static const char bold[]{ 0x1B,'[','1','m','\0' };

	/*ESC[38; 2; {r}; {g}; {b}m*/

	static const char rgb_sequence[]{ 0x1B,'[','3','8',';','5',';','5','0',';','1','6','3',';','2','0','1','m' ,'\0' };

	static const char reset[]{ 0x1B,'[','0','m','\0' };

	__int8 value = 2;
	/*return os << begin_sequence << 91 << ';' << 82 << 'm' << ++delim_count << reset;*/
	return os << rgb_sequence << ++delim_count << reset;
}

//void ColorPrint(const char* text, int fg_color, int bg_color)
//{
//	static const char begin_sequence[]{ 0x1B,'[','\0' };
//	static const char reset[]{ 0x1B,'[','0','m','\0' };
//
//	std::cout << begin_sequence << fg_color << ';' << bg_color << 'm' << text << reset << "\n";
//}

/*std::cout << highlight;*/
/*std::cout << bold_on << "bold" << bold_off << " non-bold" << std::endl;*/

//std::ostream& bold_on(std::ostream& os)
//{
//	static const char begin_sequence[]{ 0x1B,'[','\0' };
//	return os << "ESC[<1> m";
//}
//
//std::ostream& bold_off(std::ostream& os)
//{
//	return os << "ESC[<22> m";
//}