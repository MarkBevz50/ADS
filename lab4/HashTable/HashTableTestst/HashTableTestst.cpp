#include "pch.h"
#include "CppUnitTest.h"
#include "../HashTable/HashTable.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTests
{
    TEST_CLASS(HashTableTests)
    {
    public:
        TEST_METHOD(TestPutPair)
        {
            // Arrange
            HashTable table;

            // Act
            table.PutPair(1, "Value1");
            table.PutPair(2, "Value2");

            // Assert
            Assert::AreEqual(std::string("Value1"), table.GetValue(1));
            Assert::AreEqual(std::string("Value2"), table.GetValue(2));
        }

        TEST_METHOD(TestEraseByKey)
        {
            // Arrange
            HashTable table;
            table.PutPair(1, "Value1");
            table.PutPair(2, "Value2");

            // Act
            table.EraseByKey(1);

            // Assert
            Assert::IsFalse(table.CheckByKey(1));
            Assert::AreEqual(std::string("Value2"), table.GetValue(2));
        }

        TEST_METHOD(TestCheckByKey)
        {
            // Arrange
            HashTable table;
            table.PutPair(1, "Value1");

            // Assert
            Assert::IsTrue(table.CheckByKey(1));
            Assert::IsFalse(table.CheckByKey(2));
        }

        TEST_METHOD(TestGetKey)
        {
            // Arrange
            HashTable table;
            table.PutPair(1, "Value1");

            // Act
            int key = table.GetKey("Value1");

            // Assert
            Assert::AreEqual(1, key);
        }

        TEST_METHOD(TestGetValue)
        {
            // Arrange
            HashTable table;
            table.PutPair(1, "Value1");

            // Assert
            Assert::AreEqual(std::string("Value1"), table.GetValue(1));
        }

        TEST_METHOD(TestGetKeys)
        {
            // Arrange
            HashTable table;
            table.PutPair(1, "Value1");
            table.PutPair(2, "Value2");

            // Act
            int size = 0;
            int* keys = table.GetKeys(size);

            // Assert
            Assert::AreEqual(2, size);
            Assert::AreEqual(1, keys[0]);
            Assert::AreEqual(2, keys[1]);
            delete[] keys;
        }

        TEST_METHOD(TestGetValues)
        {
            HashTable table;
            table.PutPair(1, "Value1");
            table.PutPair(2, "Value2");

            // Act
            int size = 2; // Встановлюємо розмір масиву
            std::string* values = table.GetValues(size);

            // Assert
            Assert::AreEqual(2, size);
            Assert::AreEqual(std::string("Value1"), values[0]);
            Assert::AreEqual(std::string("Value2"), values[1]);

            // Звільнення пам'яті
            delete[] values;
        }

        TEST_METHOD(TestOperatorBracket)
        {
            // Arrange
            HashTable table;
            table.PutPair(1, "Value1");

            // Act
            std::string& value = table[1];

            // Assert
            Assert::AreEqual(std::string("Value1"), value);
        }
    };
}