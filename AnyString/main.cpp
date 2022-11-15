
void ColorPrint(const char* text, int fg_color, int bg_color);

#include "foo.h"

#include <iostream>

int main(void) {

	{
		std::cout << "===================================" << "\n";
		std::cout << "default constructor" << "\n" << "\n";
		m_string foo1;
		std::cout << foo1 << "\n";
	}

	{
		std::cout << "===================================" << "\n";
		std::cout << "converting constructor with CharT" << "\n" << "\n";
		m_string foo1('a');
		std::cout << foo1 << "\n";
	}

	{
		std::cout << "===================================" << "\n";
		std::cout << "converting constructors with CharT*" << "\n" << "\n";
		//converting constructor with char*
		m_string foo1("Hallelujah");
		std::cout << foo1 << "\n";

		m_string  foo2("GOD");
		std::cout << foo2 << "\n";

		const m_string  foo3("Maria");
		std::cout << foo3 << "\n";
	}

	{
		std::cout << "===================================" << "\n";
		std::cout << "converting constructor with std::string" << "\n" << "\n";

		std::string foo1("Father");
		m_string foo2(foo1);
		std::cout << foo2 << "\n";
	}

	{
		std::cout << "===================================" << "\n";
		std::cout << "	copying constructor" << "\n" << "\n";

		m_string foo1("Cappuchino");
		std::cout << foo1 << "\n";
		m_string foo2(foo1);
		std::cout << foo2 << "\n";
	}

	{
		std::cout << "===================================" << "\n";
		std::cout << "operator =" << "\n" << "\n";

		m_string foo1("Cappuchino");
		std::cout << foo1 << "\n";
		m_string foo2 = foo1;
		std::cout << foo2 << "\n";
	}

	{
		std::cout << "===================================" << "\n";
		std::cout << " operator +=" << "\n" << "\n";

		m_string foo1("Kratos says:");
		m_string foo2("\"ragnarok comes\"");

		foo1 += foo2;
		foo1 += " TODAY comes...either";

		std::cout << foo1 << "\n";
	}

	{
		std::cout << "===================================" << "\n";
		std::cout << "operator + " << "\n" << "\n";

		m_string foo1("Kratos says:");
		m_string foo2("\"ragnarok comes\"");

		m_string foo3("\"bob\"");

		std::cout << foo2 + foo1 << "\n";
	}

	{
		std::cout << "===================================" << "\n";
		std::cout << "operator = & operator + " << "\n" << "\n";

		m_string foo1("Kratos says:");
		m_string foo2("\"ragnarok comes\"");

		m_string foo3("\"bob\"");

		foo3 = foo1 + foo2;
		std::cout << foo3 << "\n";
	}

	{
		m_string foo3("\"bob\"");

		//TODO
		/*foo3 = "ARFA" + foo3;
		std::cout << foo3 << "\n";*/
	}

	{
		std::cout << "===================================" << "\n";
		std::cout << "	operator []" << "\n" << "\n";

		/*m_string foo1("\"bob\"");
		std::cout << foo1[0] << "\n";
		foo1[0] = 'B';
		std::cout << foo1 << "\n";*/

		m_string foo1("\"bob\"");
		foo1[0];
		foo1[0] = 'B';
		std::cout << foo1 << "\n";
		
	}

	//	std::cout << "===================================" << "\n";
	//	std::cout << "	operators += and +" << "\n" << "\n";
	////operators += and +
	//strEmpl6 += "is" + strEmpl4;
	//	std::cout << strEmpl6 << "\n";

	//	std::cout << "===================================" << "\n";
	//	std::cout << "	lower&upper case" << "\n" << "\n";
	////lower&upper case 
	//std::cout << "\n";
	//std::cout << strEmpl6.toLowerCase() << "\n";
	//std::cout << strEmpl6.toUpperCase() << "\n";

	//std::cout << "===================================" << "\n";
	//	std::cout << "	equality operators" << "\n" << "\n";
	////eq operators
	//std::cout << std::boolalpha;
	//String com1("a"); String com2("b");

	//std::cout << (com1 == com2) << "\n";
	//std::cout << (com1 != com2) << "\n";
	//std::cout << (com1 >= com2) << "\n";
	//std::cout << (com1 <= com2) << "\n";
	//std::cout << (com1 > com2) << "\n";
	//std::cout << (com1 < com2) << "\n";
	//std::cout << std::noboolalpha << "\n";

	//std::cout << "===================================" << "\n";

	//String s("Tra-ta-ta");
	//const char* ps = static_cast<const char*> (s);
	//std::cout << (s += ps) << ';' << std::endl;

	//ColorPrint("some text", 91, 102);
	//
	return 0;
}

void ColorPrint(const char* text, int fg_color, int bg_color)
{
	static const char begin_sequence[]{ 0x1B,'[','\0' };
	static const char reset[]{ 0x1B,'[','0','m','\0' };

	std::cout << begin_sequence << fg_color << ';' << bg_color << 'm' << text << reset;
}

