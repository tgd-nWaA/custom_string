#ifndef InsertionsAndDeletionsTest_H_
#define InsertionsAndDeletionsTest_H_

#include "Test.h"
#include "String.h"
namespace Testing
{
	class InsertionsAndDeletions : public Test
	{
	public:
		InsertionsAndDeletions();
		~InsertionsAndDeletions();
	private:
		void Setup();
		void Teardown();
		String m_String;

		//push_back
		void AddCharacterToEnd();

		//pop_back
		void EraseLastCharacter();

		//insert
		void InsertCharactersIntoString();

		//erase
		void ErasePartOfString();
	};
}

#endif // InsertionsAndDeletionsTest_H_