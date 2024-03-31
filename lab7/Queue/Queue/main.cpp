#include "Queue.h"
int main()
{
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Queue size: " << myQueue.getSize() << std::endl;

    std::cout << "First elem in queue: " << myQueue.getFront() << std::endl;

    std::cout << "dequeue :" << myQueue.getFront() << '\n';
    myQueue.dequeue();

    std::cout << "First new elem in queue: " << myQueue.getFront() << std::endl;
    std::cout << "New queue size: " << myQueue.getSize() << std::endl;

    std::cout << "Prioryty queue: \n";
    PriorityQueue Queue2;
    Queue2.Enqueue(1, 3);
    Queue2.Enqueue(7, 1);
    Queue2.Enqueue(4, 2);
    Queue2.Enqueue(3, 1);
    std::cout << "Queue size: " << Queue2.getSize() << std::endl;

    std::cout << "First elem in queue: " << Queue2.getFront() << std::endl;

    Queue2.dequeue();

    std::cout << "First new elem in queue: " << Queue2.getFront() << std::endl;
    std::cout << "New queue size: " << Queue2.getSize() << std::endl;
   /* Queue Empty;
    Empty.dequeue();*/
    return 0;
}
