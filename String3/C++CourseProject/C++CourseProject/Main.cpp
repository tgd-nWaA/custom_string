#include "TestDriver.h"
#include <iostream>

void RunTests();

int main()
{
	RunTests();

	int wait = 0;
	std::cin >> wait;

	return 0;
}


void RunTests()
{
	try
	{
	Testing::TestDriver * td = new Testing::TestDriver();
	td->BeginTesting();
	delete td;
	}
	catch(...)
	{
		std::cout << "Exception occurred" << std::endl;
	}
}