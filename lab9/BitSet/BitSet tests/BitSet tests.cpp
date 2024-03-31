#include "pch.h"
#include "CppUnitTest.h"
#include "../BitSet/BitSet.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace BitSettests
{
    TEST_CLASS(BitSettests)
    {
    public:
        TEST_METHOD(TestAdd1)
        {
            BitSet mySet;
            mySet.add(2);
            Assert::IsTrue(mySet.contains(2), L"Failed to add element 2");
        }
        TEST_METHOD(TestAdd2)
        {
            // ���� 2: ������ ������� 5 (��������� 6-� ��)
            BitSet mySet;
            mySet.add(5);
            Assert::IsTrue(mySet.contains(5), L"Failed to add element 5");
        }
        TEST_METHOD(TestRemove1)
        {
            BitSet mySet;
            //���� ������� 3, ���� ��������� ����
            mySet.add(3);
            mySet.remove(3);
            Assert::IsFalse(mySet.contains(3), L"Failed to remove element 3");
        }
        TEST_METHOD(TestRemove2)
        {
            BitSet mySet;
            // ���� 2: ������ ������� 0, ���� ��������� ����
            mySet.add(0);
            mySet.remove(0);
            Assert::IsFalse(mySet.contains(0), L"Failed to remove element 0");
        }
        TEST_METHOD(TestContains1)
        {
            BitSet mySet;
            // ���� 1: ����������, �� ������� ������ ������� �������
            mySet.add(4);
            Assert::IsTrue(mySet.contains(4), L"Contains method failed for element 4");
        }
        TEST_METHOD(TestContains2)
        {
            BitSet mySet;

            // ���� 2: ����������, �� ������� �� ������ �������, ���� �� ��� �������
            Assert::IsFalse(mySet.contains(7), L"Contains method failed for non-existing element 7");
        }
        TEST_METHOD(TestMerge1)
        {
            BitSet set1, set2;
            // ���� 1: ������ ������� ������
            BitSet mergedSet1 = set1.merge(set2);
            Assert::IsTrue(mergedSet1.contains(0) == false, L"Merged set is not empty");
        }
        TEST_METHOD(TestMerge2)
        {
            BitSet set1, set2;
            // ���� 2: ������ ������ � ���������� ����������
            set1.add(2);
            set1.add(4);
            set2.add(4);
            set2.add(6);
            BitSet mergedSet2 = set1.merge(set2);
            Assert::IsTrue(mergedSet2.contains(2), L"Merged set doesn't contain element 2");
            Assert::IsTrue(mergedSet2.contains(4), L"Merged set doesn't contain element 4");
            Assert::IsTrue(mergedSet2.contains(6), L"Merged set doesn't contain element 6");
        }
    };
}