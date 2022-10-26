#include "MiscellaneousTests.h"

using namespace Testing;

MiscellaneousTests::MiscellaneousTests(void)
{
	m_TestCategoryName = "Miscellaneous Tests";

	//StringsAreEqual
	m_Tests.push_back([&]() { return StringsAreEqualWorksWithEmptyStringsTest(); });
	m_Tests.push_back([&]() { return StringsAreEqualWorksWhenOtherStringIsEmptyTest(); });
	m_Tests.push_back([&]() { return StringsAreEqualWorksWithDifferentStringsWithSameBeginningTest(); });	
	m_Tests.push_back([&]() { return StringsAreEqualReturnsTrueWhenStringsAreSameTest(); });

	//StringLength
	m_Tests.push_back([&]() { return StringLengthReturnCorrectWhenNonZeroTest(); });
	m_Tests.push_back([&]() { return StringLengthReturnZeroWhenEmptyTest(); });

	//StringCopy
	m_Tests.push_back([&]() { return StringCopyCopiesNonEmptyStringCorrectly(); });
	m_Tests.push_back([&]() { return StringCopyReturnsEmptyWhenInputEmpty(); });
}

void MiscellaneousTests::StringLengthReturnCorrectWhenNonZeroTest()
{
	ASSERT(m_String->StringLength("asdf") == 4);
}

void MiscellaneousTests::StringLengthReturnZeroWhenEmptyTest()
{
	ASSERT(m_String->StringLength("") == 0);
}

MiscellaneousTests::~MiscellaneousTests(void)
{
}


void MiscellaneousTests::Teardown()
{
	delete m_String;
}

void MiscellaneousTests::Setup()
{
	m_String = new String;
}

void MiscellaneousTests::StringCopyCopiesNonEmptyStringCorrectly()
{
	char * testString = String::StringCopy("testing");
	ASSERT(String::StringsAreEqual(testString,"testing"));
	delete [] testString;
}

void MiscellaneousTests::StringCopyReturnsEmptyWhenInputEmpty()
{
	ASSERT(String::StringsAreEqual(m_String->StringCopy(""), ""));
}


void MiscellaneousTests::StringsAreEqualWorksWithEmptyStringsTest()
{
	char* testStringOne = "";
	char* testStringTwo = "";

	bool result =  String::StringsAreEqual(testStringOne,testStringTwo);

	ASSERT(result);
}
void MiscellaneousTests::StringsAreEqualWorksWhenOtherStringIsEmptyTest()
{
	char* testStringOne = "";
	char* testStringTwo = "asdf";

	bool result =  String::StringsAreEqual(testStringOne,testStringTwo);

	ASSERT(!result);
}
void MiscellaneousTests::StringsAreEqualWorksWithDifferentStringsWithSameBeginningTest()
{
	char* testStringOne = "asdf";
	char* testStringTwo = "asdf fdsa";

	bool result =  String::StringsAreEqual(testStringOne,testStringTwo);

	ASSERT(!result);
}
void MiscellaneousTests::StringsAreEqualReturnsTrueWhenStringsAreSameTest()
{
	char* testStringOne = "asdffdsa";
	char* testStringTwo = "asdffdsa";

	bool result =  String::StringsAreEqual(testStringOne,testStringTwo);

	ASSERT(result);
}