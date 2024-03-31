#include "Queue.h"

Node::Node(int data)
	:data(data), next(nullptr), prev(nullptr)
{
}

Queue::Queue()
	:front(nullptr), rear(nullptr)
{
}

Queue::~Queue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

void Queue::enqueue(int data)
{
	Node* newNode = new Node(data);
	if (isEmpty())
	{
		front = rear = newNode;
	}
	else
	{
		rear->next = newNode;
		newNode->prev = rear;
		rear = newNode;
	}
}

void Queue::dequeue()
{
	if (isEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	Node* temp = front;
	front = front->next;
	if (front != nullptr) {
		front->prev = nullptr;
	}
	else {
		rear = nullptr;
	}
	delete temp;

}

int Queue::getFront()
{
	if (isEmpty())
	{
		throw std::out_of_range("Queue is empty!");
	}
	return front->data;
}

int Queue::getSize()
{
	int size = 0;
	Node* current = front;
	while (current != nullptr)
	{
		current = current->next;
		++size;
	}
	return size;
}

bool Queue::isEmpty()
{
	return front == 0;
}
PriorityQueue::PriorityQueue() : front(nullptr) {}

void PriorityQueue::Enqueue(int data, int priority) {
	PriorityNode* newNode = new PriorityNode(data, priority);
	if (isEmpty() || priority <= front->priority) {
		newNode->next = front;
		front = newNode;
	}
	else {
		PriorityNode* current = front;
		while (current->next != nullptr && current->next->priority >= priority) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void PriorityQueue::dequeue() {
	if (isEmpty()) {
		throw std::out_of_range("PriorityQueue is empty");
	}
	PriorityNode* temp = front;
	front = front->next;
	delete temp;
}

int PriorityQueue::getSize()
{
	int size = 0;
	PriorityNode* current = front;
	while (current != nullptr)
	{
		current = current->next;
		++size;
	}
	return size;
}

int PriorityQueue::getFront() const {
	if (isEmpty()) {
		throw std::out_of_range("PriorityQueue is empty");
	}
	return front->data;
}

bool PriorityQueue::isEmpty() const {
	return front == nullptr;
}

PriorityQueue::~PriorityQueue() {
	while (!isEmpty()) {
		dequeue();
	}
}