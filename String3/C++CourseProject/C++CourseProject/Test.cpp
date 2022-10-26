//Abstract/Virtual base class from which all tests should inherit from.
#include "Test.h"
#include <iostream>
using namespace Testing;


Test::Test() : m_TestsFailed(0), m_TestsTotal(0)
{

}

int Test::GetNumberOfTestsFailedInCategory()
{
	return m_TestsFailed;
}
int Test::GetNumberOfTestsInCategory()
{
	return m_TestsTotal;
}

void Test::PerformTests()
{
	int index = 0;
	for(auto it = m_Tests.begin(); it != m_Tests.end(); it++)
	{
		Setup();

		bool result = true;

		m_TestsTotal++;

		try
		{
			(*it)();		
		}
		catch(std::exception e)
		{
			m_TestsFailed++;
			
			std::cout << e.what() <<std::endl;
		}

		Teardown();
	}

	if(m_TestsFailed == 0)
		std::cout << m_TestCategoryName << " succeeded. " << m_TestsTotal << " out of " << m_TestsTotal << " tests passed"  << std::endl;
	else
		std::cout << m_TestCategoryName << " failed. " << m_TestsFailed << " out of " << m_TestsTotal << " tests failed." << std::endl;
}