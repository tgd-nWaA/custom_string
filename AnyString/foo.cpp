#include "foo.h"

#include <iostream>

int main(void) {
	
	
	{
		m_string foo1("Shmarkli");
		std::cout << foo1 << "\n";

		m_string foo2; foo2 = foo1;
	}

	{
		wm_string str(L"2Shmarkli");
		std::wcout << str << "\n";
	}

	{
		std::wstring foo{L"grjhfkld"};
		std::wcout << foo << "\n";
	}
	
	return 0;
};
