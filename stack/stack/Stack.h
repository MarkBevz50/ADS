#pragma once
// Stack.h



#include <iostream>

class NodeStack {
public:
    int data;
    NodeStack* next;

    NodeStack(int value);
};

class Stack {
private:
    NodeStack* top;

public:
    Stack();
    ~Stack();

    void Push(int value);
    void Pop();
    bool isEmpty() const;
    void Clear();
    int Top() const;
    int Size() const;
};

