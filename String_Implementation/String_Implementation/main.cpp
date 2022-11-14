#include "String.h"

#include <iostream>

int main(void) {

	std::cout << "===================================" << "\n";
	std::cout << "default constructor" << "\n" << "\n";
	//default constructor
	String strEmpl;
	std::cout << strEmpl << "\n"; 

	std::cout << "===================================" << "\n";
		std::cout << "converting constructor with char" << "\n" << "\n";
	//converting constructor with char
	String strEmpl1('a');
		std::cout << strEmpl1 << "\n"; 

		std::cout << "===================================" << "\n";
		std::cout << "converting constructors with char*" << "\n" << "\n";
	//converting constructor with char*
	String strEmpl2("Hallelujah");
		std::cout << strEmpl2 << "\n";
		
	String strEmpl4("GOD");
		std::cout << strEmpl4 << "\n"; 

	const String strEmpl5("Maria");
		std::cout << strEmpl5 << "\n"; 

		std::string fatherStr("Father");
	
		std::cout << "===================================" << "\n";
		std::cout << "converting constructor with std::string" << "\n" << "\n";
	//converting constructor with std::string
	String strEmpl6(fatherStr);
		std::cout << strEmpl6 << "\n"; 

		std::cout << "===================================" << "\n";
		std::cout << "	copying constructor" << "\n" << "\n";
	//copying constructor 
	String strEmpl3(strEmpl2); 
		std::cout << strEmpl3 << "\n";
	String strEmpl7(fatherStr);
		std::cout << strEmpl7 << "\n"; 
	String strEmpl8("Cappuchino");
		std::cout << strEmpl3 << "\n"; 

		std::cout << "===================================" << "\n";
		std::cout << "	assignment operator" << "\n" << "\n";
	//assignment operator
	strEmpl3 = strEmpl8;
		std::cout << strEmpl3 << "\n";
	strEmpl3 = strEmpl2 + strEmpl4;
		std::cout << strEmpl3 << "\n"; 
	strEmpl3 = "ARFA" + strEmpl4;
		std::cout << strEmpl3 << "\n"; 

		std::cout << "===================================" << "\n";
		std::cout << "	operator []" << "\n" << "\n";
	//operator []
	std::cout << strEmpl4[0] << "\n";
	strEmpl4[0] = 'N';
		std::cout << strEmpl4 << "\n";
	std::cout << strEmpl5[0] << "\n";

		std::cout << "===================================" << "\n";
		std::cout << "	operators += and +" << "\n" << "\n";
	//operators += and +
	strEmpl6 += "is" + strEmpl4;
		std::cout << strEmpl6 << "\n";

		std::cout << "===================================" << "\n";
		std::cout << "	lower&upper case" << "\n" << "\n";
	//lower&upper case 
	std::cout << "\n";
	std::cout << strEmpl6.toLowerCase() << "\n";
	std::cout << strEmpl6.toUpperCase() << "\n";

	std::cout << "===================================" << "\n";
		std::cout << "	equality operators" << "\n" << "\n";
	//eq operators
	std::cout << std::boolalpha;
	String com1("a"); String com2("b");

	std::cout << (com1 == com2) << "\n";
	std::cout << (com1 != com2) << "\n";
	std::cout << (com1 >= com2) << "\n";
	std::cout << (com1 <= com2) << "\n";
	std::cout << (com1 > com2) << "\n";
	std::cout << (com1 < com2) << "\n";
	std::cout << std::noboolalpha << "\n";

	std::cout << "===================================" << "\n";
	
	return 0;
}