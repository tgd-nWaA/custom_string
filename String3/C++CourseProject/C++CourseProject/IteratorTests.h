#ifndef IteratorTests_H_
#define IteratorTests_H_
#include "Test.h"
#include "String.h"
namespace Testing
{
	class IteratorTests : public Test
	{
	public:
		IteratorTests();
		~IteratorTests();

	private:
		void Setup();
		void Teardown();
		

	private:
		String * m_String;


		//Iterator()
		void IteratorPointsToNullAfterDefaultConstructorTest();
		//Iterator(char *)
		void IteratorPointsToCorrectCharacterAfterCharPointerConstructor();
		//operator==(char *)
		void IteratorAssignmentOperatorReturnsFalseWhenShouldTest();
		void IteratorAssignmentOperatorReturnsTrueWhenShouldTest();
		//operator++(int)
		void IteratorPointsToCorrectCharAfterPostfixIncrementTest();
		//operator++()
		void IteratorPointsToCorrectCharAfterPrefixIncrementTest();
		//operator=(const Iterator &)
		void IteratorPointsToCorrectAfterAssignmentOperatorTest();
		//operator*()
		void IteratorDereferenceGivesCorrectData();
	};
}
#endif //IteratorTests_H_
