#include "pch.h"
#include "CppUnitTest.h"
#include "../self-balancing AVL tree/tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace treetests
{
	TEST_CLASS(treetests)
	{
	public:
		
        TEST_METHOD(TestMethod1)
        {
            // Створення дерева
            Node* root = nullptr;

            // Вставка елементів
            root = insert(root, 10);
            root = insert(root, 20);
            root = insert(root, 30);
            root = insert(root, 15);
            root = insert(root, 5);

            // Перевірка коректності вставки
            Assert::IsTrue(search(root, 10) != nullptr);
            Assert::IsTrue(search(root, 20) != nullptr);
            Assert::IsTrue(search(root, 30) != nullptr);
            Assert::IsTrue(search(root, 15) != nullptr);
            Assert::IsTrue(search(root, 5) != nullptr);

            // Видалення елемента
            root = deleteNode(root, 20);

            // Перевірка видалення елемента
            Assert::IsNull(search(root, 20));
        }

        TEST_METHOD(TestMethod2)
        {
            // Створення дерева
            Node* root = nullptr;

            // Вставка елементів
            root = insert(root, 10);
            root = insert(root, 20);
            root = insert(root, 30);
            root = insert(root, 25);

            // Перевірка балансування
            Assert::AreEqual(height(root), 3);
            Assert::AreEqual(getBalance(root), -1);
        }
        TEST_METHOD(TestMethod3)
        {
            // Створення дерева
            Node* root = nullptr;

            // Вставка елементів
            root = insert(root, 5);
            root = insert(root, 3);
            root = insert(root, 8);
            root = insert(root, 2);
            root = insert(root, 4);
            root = insert(root, 7);
            root = insert(root, 9);

            // Перевірка коректності вставки
            Assert::IsTrue(search(root, 5) != nullptr);
            Assert::IsTrue(search(root, 3) != nullptr);
            Assert::IsTrue(search(root, 8) != nullptr);
            Assert::IsTrue(search(root, 2) != nullptr);
            Assert::IsTrue(search(root, 4) != nullptr);
            Assert::IsTrue(search(root, 7) != nullptr);
            Assert::IsTrue(search(root, 9) != nullptr);

            // Видалення елементів
            root = deleteNode(root, 3);
            root = deleteNode(root, 8);

            // Перевірка видалення елементів
            Assert::IsNull(search(root, 3));
            Assert::IsNull(search(root, 8));
        }

        TEST_METHOD(TestMethod4)
        {
            // Створення дерева
            Node* root = nullptr;

            // Вставка елементів
            root = insert(root, 30);
            root = insert(root, 20);
            root = insert(root, 40);
            root = insert(root, 10);
            root = insert(root, 25);

            // Перевірка балансування
            Assert::AreEqual(height(root), 3);
            Assert::AreEqual(getBalance(root), 1);
        }
	};
}
