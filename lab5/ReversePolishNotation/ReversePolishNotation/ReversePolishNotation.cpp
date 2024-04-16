#include "pch.h"
#include "CppUnitTest.h"
#include "../ReversePolishEntry/ReverseEntry.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace PolishNotationTest
{
	TEST_CLASS(PolishNotationTest)
	{
	public:
		TEST_METHOD(TestPriority)
		{
			Assert::AreEqual(3, priority('^'));
			Assert::AreEqual(2, priority('*'));
			Assert::AreEqual(2, priority('/'));
			Assert::AreEqual(1, priority('+'));
			Assert::AreEqual(1, priority('-'));
			Assert::AreEqual(0, priority('#'));
			Assert::AreEqual(0, priority('('));
			Assert::AreEqual(0, priority(')'));
			Assert::AreEqual(-1, priority('a'));
		}

		TEST_METHOD(TestIsDigital)
		{
			Assert::IsTrue(isDigital('0'));
			Assert::IsTrue(isDigital('5'));
			Assert::IsTrue(isDigital('9'));
			Assert::IsFalse(isDigital('a'));
			Assert::IsFalse(isDigital('+'));
			Assert::IsFalse(isDigital('('));
			Assert::IsFalse(isDigital(')'));
		}

		TEST_METHOD(TestIsOperand)
		{
			Assert::IsTrue(isOperand('+'));
			Assert::IsTrue(isOperand('-'));
			Assert::IsTrue(isOperand('*'));
			Assert::IsTrue(isOperand('/'));
			Assert::IsTrue(isOperand('^'));
			Assert::IsTrue(isOperand('('));
			Assert::IsTrue(isOperand(')'));
			Assert::IsFalse(isOperand('0'));
			Assert::IsFalse(isOperand('9'));
			Assert::IsFalse(isOperand('a'));
		}

		TEST_METHOD(TestApplyOperator)
		{
			Assert::AreEqual(5.0, applyOperator(2.0, 3.0, '+'));
			Assert::AreEqual(-1.0, applyOperator(2.0, 3.0, '-'));
			Assert::AreEqual(6.0, applyOperator(2.0, 3.0, '*'));
			Assert::AreEqual(2.0 / 3.0, applyOperator(2.0, 3.0, '/'));
			Assert::AreEqual(pow(2.0, 3.0), applyOperator(2.0, 3.0, '^'));
			Assert::AreEqual(0.0, applyOperator(2.0, 3.0, '@'));
		}
	};
}