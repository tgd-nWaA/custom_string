#ifndef TestDriver_H_
#define TestDriver_H_

#include <vector>
#include "Test.h"
namespace Testing
{
	class TestDriver
	{
	public:
		TestDriver(void);
		~TestDriver(void);

		void BeginTesting();

	private:
		void PopulateTestCategoryList();

		std::vector<Test*> m_Tests;
		int m_TotalTestCount;
		int m_TotalFailedTestCount;
	};
}

#endif