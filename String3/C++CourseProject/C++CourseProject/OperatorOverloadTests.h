#ifndef OperatorOverloadTests_H_
#define OperatorOverloadTests_H_

#include "Test.h"
#include "String.h"

namespace Testing
{
	class OperatorOverloadTests : public Test
	{
	public:
		OperatorOverloadTests();
		~OperatorOverloadTests();

	private: //Present in every test category.
		void Setup();
		void Teardown();
		
	private: //Test category specific.
		String m_String;

		//Tests
		void DataCorrectAfterAssignmentToCharPointerTest();
		void EqualToOperatorReturnsTrueWhenComparingToEqualStringLiteralTest();
		void DataCorrectAfterAssignmentToOtherStringTest();
		void UsingOperatorAtReturnCorrectChar();
		void ChangingCharUsingOperatorAtWorks();
		void OperatorEqualsAndUnEqualsWorkBetweenStrings();

		void OperatorAddWorks();
		void OperatorAddToThisWorks();
	};
}

#endif //OperatorOverloadTests_H_