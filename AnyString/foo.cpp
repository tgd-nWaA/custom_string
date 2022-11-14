#include "foo.h"

#include <iostream>
#include <string>

int main(void) {
	
	
	{
		m_string foo1("Shmarkli");
		std::cout << foo1 << "\n";

		std::cout << "proxy: " << foo1[0] << "\n";
	}	

	return 0;
};
