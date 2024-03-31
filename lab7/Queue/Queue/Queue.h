#pragma once
#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node* prev;
	Node(int data);
};
class Queue
{
private:
	Node* front;
	Node* rear;
public:
	Queue();
	~Queue();
	void enqueue(int data);
	void dequeue();
	int getFront();
	int getSize();
	bool isEmpty();
};

struct PriorityNode {
	int data;
	int priority;
	PriorityNode* next;

	PriorityNode(int data, int priority) : data(data), priority(priority), next(nullptr) {}
};

class PriorityQueue {
private:
	PriorityNode* front;

public:
	PriorityQueue();
	void Enqueue(int data, int priority);
	void dequeue();
	int getSize();
	int getFront() const;
	bool isEmpty() const;
	~PriorityQueue();
};
