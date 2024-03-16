#include "pch.h"
#include "CppUnitTest.h"
#include "../stack/Stack.h"
#include <stack>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTest
{
	TEST_CLASS(StackTest)
	{
	public:
		TEST_METHOD(TestClear)
		{
			Stack TestStack;
			for (int i = 1; i <= 10; ++i) {
				TestStack.Push(i * 2);
			}
			Assert::IsFalse(TestStack.isEmpty());
			TestStack.Clear();
			Assert::IsTrue(TestStack.isEmpty());
		}
		TEST_METHOD(TestPush)
		{
			Stack TestStack;
			TestStack.Push(10);

			Assert::AreEqual(TestStack.Top(), 10);
			Assert::IsFalse(TestStack.isEmpty());
		}
		TEST_METHOD(TestPop)
		{
			Stack TestStack;
			TestStack.Push(20);
			TestStack.Push(30);

			TestStack.Pop();
			Assert::AreEqual(TestStack.Top(), 20);

			TestStack.Pop();
			Assert::IsTrue(TestStack.isEmpty());
		}

		TEST_METHOD(TestTop)
		{
			Stack TestStack;
			Assert::IsTrue(TestStack.isEmpty());

			TestStack.Push(42);
			Assert::AreEqual(TestStack.Top(), 42);

			TestStack.Push(55);
			Assert::AreEqual(TestStack.Top(), 55);
		}

		TEST_METHOD(TestIsEmpty)
		{
			Stack TestStack;
			Assert::IsTrue(TestStack.isEmpty());

			TestStack.Push(5);
			Assert::IsFalse(TestStack.isEmpty());

			TestStack.Pop();
			Assert::IsTrue(TestStack.isEmpty());
		}
		TEST_METHOD(TestPushPopWithMultipleValues)
		{
			Stack TestStack;

			for (int i = 1; i <= 100; ++i) {
				TestStack.Push(i);
			}

			Assert::AreEqual(TestStack.Top(), 100);
			Assert::IsFalse(TestStack.isEmpty());

			TestStack.Clear();

			Assert::IsTrue(TestStack.isEmpty());
		}

		TEST_METHOD(TestTopWithEmptyStack)
		{
			Stack TestStack;

			Assert::AreEqual(TestStack.Top(), 0);
			Assert::IsTrue(TestStack.isEmpty());
		}

		TEST_METHOD(TestEqualityWithSTLStack)
		{
			Stack TestStack;
			for (int i = 1; i <= 50; ++i) {
				TestStack.Push(i);
			}
			std::stack<int>  STLStack;
			for (int i = 1; i <= 50; ++i) {
				STLStack.push(i);
			}
			TestStack.Clear();
			STLStack = {}; 

			Assert::IsTrue(TestStack.isEmpty());
			Assert::IsTrue(STLStack.empty());
		}

		TEST_METHOD(TestPopWithEmptyStack)
		{
			Stack TestStack;

			TestStack.Pop();

			Assert::IsTrue(TestStack.isEmpty());
		}

	};
}