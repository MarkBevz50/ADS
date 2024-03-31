#include "pch.h"
#include "CppUnitTest.h"
#include "../Table/Table.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tabletests
{
    TEST_CLASS(Tabletests)
    {
    public:

        TEST_METHOD(PutPair_AddsElement_WhenCalled)
        {
            Table table;
            table.PutPair(1, "Value1");
            Assert::AreEqual(1, table.GetQuantity());
            Assert::IsTrue(table.CheckByKey(1));
        }

      /*  TEST_METHOD(PutPair_UpdatesValue_WhenKeyExists)
        {
            Table table;
            table.PutPair(1, "Value1");
            table.PutPair(1, "UpdatedValue");
            Assert::AreEqual(1, table.GetQuantity());
            Assert::AreEqual("UpdatedValue", table.GetValue(1).c_str());
        }*/
        TEST_METHOD(PutPair_UpdatesValue_WhenKeyExists)
        {
            Table table;
            table.PutPair(1, "Value1");
            try {
                table.PutPair(1, "UpdatedValue");
                Assert::Fail(L"An exception should have been thrown");
            }
            catch (const std::runtime_error& e) {
                Assert::AreEqual("Key already exists in the table.", e.what());
            }
            Assert::AreEqual(1, table.GetQuantity());
            Assert::AreEqual(std::string("Value1"), table.GetValue(1));
        }
        TEST_METHOD(EraseByKey_RemovesElement_WhenCalled)
        {
            Table table;
            table.PutPair(1, "Value1");
            table.EraseByKey(1);
            Assert::AreEqual(0, table.GetQuantity());
            Assert::IsFalse(table.CheckByKey(1));
        }

        TEST_METHOD(EraseByKey_DoesNotRemoveElement_WhenKeyNotPresent)
        {
            Table table;
            table.PutPair(1, "Value1");
            table.EraseByKey(2);
            Assert::AreEqual(1, table.GetQuantity());
            Assert::IsTrue(table.CheckByKey(1));
        }

        TEST_METHOD(CheckByKey_ReturnsTrue_WhenKeyPresent)
        {
            Table table;
            table.PutPair(1, "Value1");
            bool result = table.CheckByKey(1);
            Assert::IsTrue(result);
        }

        TEST_METHOD(CheckByKey_ReturnsFalse_WhenKeyNotPresent)
        {
            Table table;
            table.PutPair(1, "Value1");
            bool result = table.CheckByKey(2);
            Assert::IsFalse(result);
        }
    };
}
