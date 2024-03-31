#include "pch.h"
#include "CppUnitTest.h"
#include "../Queue/Queue.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueUnitTest
{
    TEST_CLASS(QueueTests)
    {
    public:

        TEST_METHOD(TestEnqueue)
        {
            Queue queue;
            queue.enqueue(1);
            queue.enqueue(2);
            queue.enqueue(3);

            Assert::AreEqual(3, queue.getSize());
        }

        TEST_METHOD(TestEnqueueDequeue)
        {
            Queue queue;
            queue.enqueue(1);
            queue.enqueue(2);
            queue.enqueue(3);

            queue.dequeue();

            Assert::AreEqual(2, queue.getSize());
        }

        TEST_METHOD(TestDequeueFromEmptyQueue)
        {
            Queue queue;
            try {
                queue.dequeue();
                Assert::Fail(L"Expected an exception");
            }
            catch (const std::exception&) {
                // Test passed: Expected an exception
            }
        }

        TEST_METHOD(TestGetFront)
        {
            Queue queue;
            queue.enqueue(1);
            queue.enqueue(2);
            queue.enqueue(3);

            Assert::AreEqual(1, queue.getFront());
        }

        TEST_METHOD(TestGetFrontFromEmptyQueue)
        {
            Queue queue;
            try {
                queue.getFront();
                Assert::Fail(L"Expected an exception");
            }
            catch (const std::exception&) {
                // Test passed: Expected an exception
            }
        }

        TEST_METHOD(TestMultipleEnqueueDequeue)
        {
            Queue queue;
            queue.enqueue(1);
            queue.enqueue(2);
            queue.dequeue();
            queue.enqueue(3);
            queue.dequeue();

            Assert::AreEqual(1, queue.getSize());
        }

        TEST_METHOD(TestEnqueueDifferentDataTypes)
        {
            Queue queue;
            queue.enqueue(1);
            queue.enqueue(2.5);
            queue.enqueue('c');

            Assert::AreEqual(3, queue.getSize());
        }

        TEST_METHOD(TestEmptyQueueAfterDequeueAll)
        {
            Queue queue;
            queue.enqueue(1);
            queue.enqueue(2);
            queue.enqueue(3);
            queue.dequeue();
            queue.dequeue();
            queue.dequeue();

            Assert::IsTrue(queue.isEmpty());
        }
    };
}
namespace PriorityQueueUnitTest
{
    TEST_CLASS(PriorityQueueTests)
    {
    public:

        TEST_METHOD(TestEnqueueWithPriority)
        {
            PriorityQueue queue;
            queue.Enqueue(1, 2); // Елемент з пріоритетом 2
            queue.Enqueue(2, 1); // Елемент з пріоритетом 1
            queue.Enqueue(3, 3); // Елемент з пріоритетом 3

            Assert::AreEqual(3, queue.getSize());
        }

        TEST_METHOD(TestEnqueueDequeueWithPriority)
        {
            PriorityQueue queue;
            queue.Enqueue(1, 2);
            queue.Enqueue(2, 1);
            queue.Enqueue(3, 3);

            queue.dequeue();

            Assert::AreEqual(2, queue.getSize());
        }

        TEST_METHOD(TestDequeueFromEmptyPriorityQueue)
        {
            PriorityQueue queue;
            try {
                queue.dequeue();
                Assert::Fail(L"Expected an exception");
            }
            catch (const std::exception&) {
                // Test passed: Expected an exception
            }
        }

        TEST_METHOD(TestGetFrontWithPriority)
        {
            PriorityQueue queue;
            queue.Enqueue(1, 2);
            queue.Enqueue(2, 1);
            queue.Enqueue(3, 3);

            Assert::AreEqual(2, queue.getFront());
        }

        TEST_METHOD(TestGetFrontFromEmptyPriorityQueue)
        {
            PriorityQueue queue;
            try {
                queue.getFront();
                Assert::Fail(L"Expected an exception");
            }
            catch (const std::exception&) {
                // Test passed: Expected an exception
            }
        }

        TEST_METHOD(TestMultipleEnqueueDequeueWithPriority)
        {
            PriorityQueue queue;
            queue.Enqueue(1, 2);
            queue.Enqueue(2, 1);
            queue.dequeue();
            queue.Enqueue(3, 3);
            queue.dequeue();

            Assert::AreEqual(1, queue.getSize());
        }

        TEST_METHOD(TestEnqueueWithSamePriority)
        {
            PriorityQueue queue;
            queue.Enqueue(1, 2);
            queue.Enqueue(2, 2);
            queue.Enqueue(3, 2);

            Assert::AreEqual(3, queue.getSize());
        }

        TEST_METHOD(TestEnqueueDifferentDataTypesWithPriority)
        {
            PriorityQueue queue;
            queue.Enqueue(1, 2);
            queue.Enqueue(2.5, 1);
            queue.Enqueue('c', 3);

            Assert::AreEqual(3, queue.getSize());
        }
    };
}