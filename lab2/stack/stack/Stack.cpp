#include "Stack.h"

NodeStack::NodeStack(int value)
    : data(value), next(nullptr) {
}

Stack::Stack()
    : top(nullptr) {
}

Stack::~Stack() {
    while (!isEmpty()) {
        Pop();
    }
}

void Stack::Push(int value) {
    NodeStack* newNode = new NodeStack(value);
    newNode->next = top;
    top = newNode;
}

void Stack::Pop() {
    if (!isEmpty()) {
        NodeStack* temp = top;
        top = top->next;
        delete temp;
    }
    else {
        std::cout << "Stack is empty!";
    }
}
void Stack::Clear() {
    while (!isEmpty()) {
        Pop();
    }
}
bool Stack::isEmpty() const {
    return top == nullptr;
}

int Stack::Top() const {
    if (!isEmpty()) {
        return top->data;
    }
    else {
        std::cout << "Stack is empty.\n";
        return 0;
    }
}

int Stack::Size() const {
    int count = 0;
    NodeStack* current = top;

    while (current != nullptr) {
        ++count;
        current = current->next;
    }

    return count;
}
