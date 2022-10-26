#include "InsertionsAndDeletions.h"


using namespace Testing;

InsertionsAndDeletions::InsertionsAndDeletions() : m_String()
{
	
	m_TestCategoryName = "String Constructor and Initialization Tests";
	m_Tests.push_back([&]() { return ErasePartOfString(); });
	m_Tests.push_back([&]() { return InsertCharactersIntoString(); });
	m_Tests.push_back([&]() { return EraseLastCharacter(); });
	m_Tests.push_back([&]() { return AddCharacterToEnd(); });

}

InsertionsAndDeletions::~InsertionsAndDeletions()
{
}

void InsertionsAndDeletions::ErasePartOfString()
{
	m_String = "testdetest";

	m_String.erase(4, 2);

	ASSERT(m_String == "testtest");


	m_String = "newtest";
	m_String.erase(0, 10);
	ASSERT(m_String == "");


	m_String = "testremovetest";
	m_String.erase(4, 6);
	ASSERT(m_String == "testtest");
}

void InsertionsAndDeletions::InsertCharactersIntoString()
{
	String theTruth = "Hitler was a nice guy";
	m_String = "n't";
	theTruth.insert(10, m_String);
	ASSERT(theTruth == "Hitler wasn't a nice guy");
}

void InsertionsAndDeletions::EraseLastCharacter()
{
	m_String = "derp";
	m_String.pop_back();
	ASSERT(m_String == "der");
}

void InsertionsAndDeletions::AddCharacterToEnd()
{
	m_String = "testing";
	String other("testingk");
	m_String.push_back('k');

	ASSERT(m_String == other);
}

void InsertionsAndDeletions::Setup()
{
}

void InsertionsAndDeletions::Teardown()
{
}