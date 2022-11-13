#include "foo.h"

#include <iostream>

int main(void) {
	
	
	{
		String<char> str1("Shmarkli");
		std::cout << str1 << "\n";

		String<char> str2 = str1;

		str2[3] = 's';

		std::cout << str2 << "\n";
		
	}

	{
		String<wchar_t> str(L"2Shmarkli");
		std::wcout << str.c_str() << L"\n";
	}

	return 0;
};
