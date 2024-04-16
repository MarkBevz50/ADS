#include "pch.h"
#include "CppUnitTest.h"
#include "../SparseMatrix/SparseMatrix.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace SparseMatrixTest
{
	TEST_CLASS(SparseMatrixTest)
	{
	public:

		TEST_METHOD(AddElementTest)
		{
			SparseMatrix matrix(3, 3);
			matrix.addElement(0, 0, 1);
			matrix.addElement(1, 1, 2);
			matrix.addElement(2, 2, 3);

			Assert::AreEqual(matrix.getElement(0, 0), 1);
			Assert::AreEqual(matrix.getElement(1, 1), 2);
			Assert::AreEqual(matrix.getElement(2, 2), 3);
			Assert::AreEqual(matrix.getElement(0, 1), 0); 
		}
		TEST_METHOD(AddElementTest2)
		{
			SparseMatrix matrix(3, 3);

			matrix.addElement(1, 1, 5);
			matrix.addElement(2, 2, 10);

			Assert::AreEqual(matrix.getElement(1, 1), 5);
			Assert::AreEqual(matrix.getElement(2, 2), 10);
			Assert::AreEqual(matrix.getElement(0, 0), 0);
		}
		
		TEST_METHOD(GetElementTest)
		{
			SparseMatrix matrix(3, 3);
			matrix.addElement(0, 0, 1);
			matrix.addElement(1, 1, 2);
			matrix.addElement(2, 2, 3);

			Assert::AreEqual(matrix.getElement(0, 0), 1);
			Assert::AreEqual(matrix.getElement(1, 1), 2);
			Assert::AreEqual(matrix.getElement(2, 2), 3);
			Assert::AreEqual(matrix.getElement(0, 1), 0); 
		}
		TEST_METHOD(GetElementTest1)
		{
			// Arrange
			SparseMatrix matrix(3, 3);
			matrix.addElement(1, 1, 5);

			// Act
			int element = matrix.getElement(1, 1);

			// Assert
			Assert::AreEqual(element, 5);
		}
		TEST_METHOD(GetSizeTest)
		{
			SparseMatrix matrix(3, 4);
			Assert::AreEqual(matrix.getSize(), 12);

			matrix.addElement(0, 0, 1);
			Assert::AreEqual(matrix.getSize(), 12);
		}

	};
}