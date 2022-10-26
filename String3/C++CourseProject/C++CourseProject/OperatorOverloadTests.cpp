#include "OperatorOverloadTests.h"
#include "String.h"

using namespace Testing;

OperatorOverloadTests::OperatorOverloadTests() : m_String()
{
	m_TestCategoryName = "Operator Overload Tests";

	//Add all test functions and their names here.
	m_Tests.push_back([&]() { return DataCorrectAfterAssignmentToCharPointerTest(); });
	m_Tests.push_back([&]() { return EqualToOperatorReturnsTrueWhenComparingToEqualStringLiteralTest(); });
	m_Tests.push_back([&]() { return DataCorrectAfterAssignmentToOtherStringTest();});
	m_Tests.push_back([&]() { return UsingOperatorAtReturnCorrectChar();});
	m_Tests.push_back([&]() { return ChangingCharUsingOperatorAtWorks(); });
	m_Tests.push_back([&]() { return OperatorEqualsAndUnEqualsWorkBetweenStrings(); });
	m_Tests.push_back([&]() { return OperatorAddWorks(); });
	m_Tests.push_back([&]() { return OperatorAddToThisWorks(); });

}


OperatorOverloadTests::~OperatorOverloadTests()
{
}
void OperatorOverloadTests::OperatorAddWorks()
{
	m_String = "test";
	String other = "ing";

	String third = m_String + other;

	ASSERT(third == "testing");
}
void OperatorOverloadTests::OperatorAddToThisWorks()
{
	m_String = "ing";
	String other = "test";

	other += m_String;

	ASSERT(other == "testing");
}

void OperatorOverloadTests::ChangingCharUsingOperatorAtWorks()
{
	m_String = "1234";
	m_String[0] = '2';
	ASSERT(m_String == "2234");
}
void OperatorOverloadTests::UsingOperatorAtReturnCorrectChar()
{
	m_String = "0123456789";
	ASSERT(m_String[6] == '6');
}

void OperatorOverloadTests::DataCorrectAfterAssignmentToOtherStringTest()
{
	String otherString("asdf");
	m_String = otherString;

	ASSERT(m_String == "asdf");
}

void OperatorOverloadTests::DataCorrectAfterAssignmentToCharPointerTest()
{
	m_String = "teststring";
	ASSERT(m_String == "teststring");
}

void OperatorOverloadTests::OperatorEqualsAndUnEqualsWorkBetweenStrings()
{
	String other("cheers");
	m_String = "yeah";

	ASSERT(other != m_String);

	m_String = "cheers";

	ASSERT(other == m_String);
}

void OperatorOverloadTests::EqualToOperatorReturnsTrueWhenComparingToEqualStringLiteralTest()
{
	m_String = "teststring";

	ASSERT(m_String == "teststring");
}
void OperatorOverloadTests::Setup()
{
}

void OperatorOverloadTests::Teardown()
{
}