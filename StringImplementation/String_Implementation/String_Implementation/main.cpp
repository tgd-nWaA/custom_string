#include "String.h"

#include <iostream>

int main(void) {

	//default constructor
	String strEmpl;
	std::cout << strEmpl << "\n"; //check

	//converting constructor with char
	String strEmpl1('a');
		std::cout << strEmpl1 << "\n"; //check

	//converting constructor with char*
	String strEmpl2("Hallelujah");
		std::cout << strEmpl2 << "\n"; //check
		
	String strEmpl4("GOD");
		std::cout << strEmpl4 << "\n"; //check

	const String strEmpl5("Maria");
		std::cout << strEmpl5 << "\n"; //check

		std::string fatherStr("Father");
	//converting constructor with std::string
	String strEmpl6(fatherStr);
		std::cout << strEmpl6 << "\n"; //check


	//copying constructor 
	String strEmpl3(strEmpl2); 
		std::cout << strEmpl3 << "\n"; //check
	String strEmpl7(fatherStr);
		std::cout << strEmpl7 << "\n"; //check
	String strEmpl8("Cappuchino");
		std::cout << strEmpl3 << "\n"; //check

	//assignment operator
	strEmpl3 = strEmpl8;
		std::cout << strEmpl3 << "\n"; //check
	strEmpl3 = strEmpl2 + strEmpl4;
		std::cout << strEmpl3 << "\n";

	//operator []
	std::cout << strEmpl4[0] << "\n";
	std::cout << strEmpl5[0] << "\n";

	//operators += and +
	strEmpl6 += "is" + strEmpl4;
	std::cout << strEmpl6 << "\n";

	std::cout << strEmpl6.toLowerCase() << "\n";
	std::cout << strEmpl6.toUpperCase() << "\n";

	return 0;
}