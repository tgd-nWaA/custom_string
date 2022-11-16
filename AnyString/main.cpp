

#include "m_string.h"

#include <iostream>

const char* res_is = "|>Result is: ";
const wchar_t* wres_is = L"|>Result is: ";

const char* out_delimeter(char* str);

//work with for each???

int main(void) {	

	{		
		
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";
		m_string foo1;
		std::cout << res_is << foo1 << "\n";
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";
		wm_string foo1;
		std::wcout << wres_is << foo1 << "\n";
	}
	
	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";
		m_string foo1('a');
		std::cout << res_is << foo1 << "\n";
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";
		
		m_string foo1("Hallelujah");
		std::cout << res_is << foo1 << "\n";

		m_string  foo2("GOD");
		std::cout << res_is << foo2 << "\n";

		const m_string  foo3("Maria");
		std::cout << res_is << foo3 << "\n";
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";

		std::string foo1("Father");
		m_string foo2(foo1);
		std::cout << res_is << foo2 << "\n";
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";

		m_string foo1("Cappuchino");
		m_string foo2 = foo1;
		std::cout << res_is << foo2 << "\n";
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";

		m_string foo1("Kratos says:");
		m_string foo2("\"ragnarok comes\"");

		foo1 += foo2;

		std::cout << res_is << foo1 << "\n";
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";

		m_string foo1("bob");
		m_string foo2(" loves cheeseburgers and women");

		std::cout << res_is << foo1 + foo2 << "\n";
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";

		m_string foo1("Kratos says:");
		m_string foo2("ragnarok comes");

		m_string foo3("bob");

		foo3 = foo1 + foo2;
		std::cout << res_is << foo3 << "\n";
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";

		const m_string foo1("bob");

		std::cout << res_is << foo1[0] << "\n";
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";
		m_string foo1("bob");
		foo1[0] = 'B';

		std::cout << res_is << foo1[0] << "\n";
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";
		m_string foo1("Bob");
		m_basic_string<char> foo2("McNaggets");
		
		foo1 += " loves " + foo2;
		foo1 += foo2 + "love";

		std::cout << res_is << foo1 << "\n";
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";
		m_string foo1("BOB");

		std::cout << foo1.tolower() << "\n";
		std::cout << foo1.touppper() << "\n";

		std::cout << res_is << foo1 << "\n";
	}	


	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";

		std::cout << std::boolalpha;

		m_string foo1("a");
		m_string foo2("b");

		std::cout << res_is << (foo1 == foo2) << "\n";
		std::cout << res_is << (foo1 != foo2) << "\n";
		std::cout << res_is << (foo1 >= foo2) << "\n";
		std::cout << res_is << (foo1 <= foo2) << "\n";
		std::cout << res_is << (foo1 > foo2) << "\n";
		std::cout << res_is << (foo1 < foo2) << "\n";

		std::cout << std::noboolalpha;
	}

	{
		std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";
		m_string s("Tra-ta-ta");
		const char* ps = static_cast<const char*> (s);
		std::cout << (s += ps) << ';' << std::endl;
	}

	

	////ColorPrint("some text", 91, 102);
	////

	std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";
	return 0;
}

void ColorPrint(const char* text, int fg_color, int bg_color)
{
	static const char begin_sequence[]{ 0x1B,'[','\0' };
	static const char reset[]{ 0x1B,'[','0','m','\0' };

	std::cout << begin_sequence << fg_color << ';' << bg_color << 'm' << text << reset;
}

//std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";
//std::cout << "|        default constructor m_string       |" << "\n";
//std::cout << "| - - - - - - - - - - - - - - - - - - - - - |" << "\n";