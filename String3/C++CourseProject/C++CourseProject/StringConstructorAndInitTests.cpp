#include "StringConstructorAndInitTests.h"
using namespace Testing;

StringConstructorAndInitTests::StringConstructorAndInitTests() : m_String()
{
	m_TestCategoryName = "String Constructor and Initialization Tests";

	//Add all test functions and their names here.
	m_Tests.push_back([&]() { return StringEmptyAfterDefaultConstructorTest(); });
	m_Tests.push_back([&]() { return DataCorrectIfCharPointerConstructorGivenEmptyStringLiteralTest(); });
	m_Tests.push_back([&]() { return DataCorrectIfCharPointerConstructorGivenNonEmptyStringLiteralTest(); });
	m_Tests.push_back([&]() { return DataCorrectIfUsedCopyConstructor(); });
}


StringConstructorAndInitTests::~StringConstructorAndInitTests(void)
{

}

void StringConstructorAndInitTests::DataCorrectIfUsedCopyConstructor()
{
	m_String = "test";
	String* test = new String(m_String);
	ASSERT(*test == "test");
}

void StringConstructorAndInitTests::DataCorrectIfCharPointerConstructorGivenEmptyStringLiteralTest()
{
	m_String =  String("");
	ASSERT(m_String == "");
}

void StringConstructorAndInitTests::DataCorrectIfCharPointerConstructorGivenNonEmptyStringLiteralTest()
{
	m_String = String("testing testing");
	ASSERT(m_String == "testing testing");
}

void StringConstructorAndInitTests::StringEmptyAfterDefaultConstructorTest()
{
	ASSERT(m_String == "");
}

void StringConstructorAndInitTests::Setup()
{
}

void StringConstructorAndInitTests::Teardown()
{
}