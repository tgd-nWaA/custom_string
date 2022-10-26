#include "TestDriver.h"

#include "OperatorOverloadTests.h"
#include "StringConstructorAndInitTests.h"
#include "MiscellaneousTests.h"
#include "IteratorTests.h"
#include "InsertionsAndDeletions.h"

#include <iostream>

using namespace Testing;

TestDriver::TestDriver(void) : m_TotalFailedTestCount(0), m_TotalTestCount(0)
{
	PopulateTestCategoryList();
}


TestDriver::~TestDriver(void)
{
	for(auto it = m_Tests.begin(); it != m_Tests.end(); it++)
	{
		delete *it;
	}
}

void TestDriver::PopulateTestCategoryList()
{
	m_Tests.push_back(new OperatorOverloadTests());
	m_Tests.push_back(new StringConstructorAndInitTests());
	m_Tests.push_back(new MiscellaneousTests());
	m_Tests.push_back(new IteratorTests());
	m_Tests.push_back(new InsertionsAndDeletions());
	//ToDo: add all test categories here.
}

void TestDriver::BeginTesting()
{
	for(auto it = m_Tests.begin(); it != m_Tests.end(); it++)
	{
		auto test = *it;
		test->PerformTests();
		m_TotalTestCount += test->GetNumberOfTestsInCategory();
		m_TotalFailedTestCount += test->GetNumberOfTestsFailedInCategory();
		std::cout << std::endl;
	}

	std::cout << "Total: " << std::endl;

	if(m_TotalFailedTestCount == 0)
	{
		std::cout << "All " << m_TotalTestCount << " tests passed" << std::endl;
	}
	else
	{
		std::cout << m_TotalFailedTestCount << " out of " << m_TotalTestCount << " tests failed." << std::endl;
	}
}