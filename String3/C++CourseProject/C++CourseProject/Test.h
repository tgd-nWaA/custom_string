#ifndef Test_H_
#define Test_H_

#include <string>
#include <vector>
#include <functional>
#include <iostream>

namespace Testing
{
	class Test
	{
	public:
		Test();
		int GetNumberOfTestsInCategory();
		int GetNumberOfTestsFailedInCategory();
		virtual void PerformTests();
	protected:
		bool m_Result;
		std::vector<std::function<void()>> m_Tests;
		std::vector<std::string> m_TestNames;

		virtual void Setup() = 0;
		virtual void Teardown() = 0;
		bool StringsAreEqual(const char *, const char *);

		int m_TestsTotal;
		int m_TestsFailed;

		std::string m_TestCategoryName;
	};
}

#endif //Test_H_


#ifdef NDEBUG
#define ASSERT(expr)
#else
#define ASSERT(expr)										\
															\
if(!(expr))													\
{															\
	throw std::exception(__FUNCTION__ "\tfailed");			\
}															\
else														\
{															\
	std::cout << __FUNCTION__ << "\tpassed" << std::endl;	\
}

#endif