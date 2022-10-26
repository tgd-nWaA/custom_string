#include "IteratorTests.h"

using namespace Testing;

IteratorTests::IteratorTests(void)
{
	m_TestCategoryName = "Iterator Tests";
	
	m_Tests.push_back([&]() { return IteratorPointsToCorrectCharacterAfterCharPointerConstructor();});
	m_Tests.push_back([&]() { return IteratorPointsToNullAfterDefaultConstructorTest();});

	m_Tests.push_back([&]() { return IteratorAssignmentOperatorReturnsFalseWhenShouldTest();});
	m_Tests.push_back([&]() { return IteratorAssignmentOperatorReturnsTrueWhenShouldTest();});

	m_Tests.push_back([&]() { return IteratorDereferenceGivesCorrectData();});
	m_Tests.push_back([&]() { return IteratorPointsToCorrectAfterAssignmentOperatorTest();});

	m_Tests.push_back([&]() { return IteratorPointsToCorrectCharAfterPostfixIncrementTest();});
	m_Tests.push_back([&]() { return IteratorPointsToCorrectCharAfterPrefixIncrementTest();});
}

void IteratorTests::IteratorDereferenceGivesCorrectData()
{
	String::Iterator it("asdf");
	ASSERT(String::StringsAreEqual(*it,"asdf"));
}

void IteratorTests::IteratorPointsToCorrectAfterAssignmentOperatorTest()
{
	String::Iterator it("fdsa");
	String::Iterator it2("1234");

	it = it2;

	ASSERT(String::StringsAreEqual(*it,"1234"));
}

void IteratorTests::IteratorPointsToCorrectCharAfterPostfixIncrementTest()
{
	String::Iterator it("0123456");

	it++;
	it++;

	ASSERT(String::StringsAreEqual(*it,"23456"));
}

void IteratorTests::IteratorPointsToCorrectCharAfterPrefixIncrementTest()
{
	String::Iterator it("0123456");

	++it;
	++it;
	++it;

	ASSERT(String::StringsAreEqual(*it,"3456"));
}

void IteratorTests::IteratorPointsToNullAfterDefaultConstructorTest()
{
	String::Iterator it;
	ASSERT(it == nullptr);
}

void IteratorTests::IteratorAssignmentOperatorReturnsTrueWhenShouldTest()
{
	String::Iterator it("a");
	ASSERT(it == "a");
}

void IteratorTests::IteratorAssignmentOperatorReturnsFalseWhenShouldTest()
{

	String::Iterator it("c");

	ASSERT(!(it == "9"));
}

void IteratorTests::IteratorPointsToCorrectCharacterAfterCharPointerConstructor()
{
	char * testString = "0123456789";

	String::Iterator it(&testString[5]);
	ASSERT(it == "5");
}

void IteratorTests::Setup()
{
	m_String = new String;
}

void IteratorTests::Teardown()
{
	delete m_String;
}

IteratorTests::~IteratorTests(void)
{
}
