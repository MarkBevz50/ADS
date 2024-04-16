#pragma once
#include <iostream>

struct Node {
    int row;
    int col;
    int value;
    Node* next;

    Node(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

class SparseMatrix {
private:
    int rows;
    int columns;
    int capacity;
    Node* head;

public:
    SparseMatrix(int r, int c) : rows(r), columns(c), head(nullptr) {}

    ~SparseMatrix() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    int getSize() const {
                return rows * columns;
           }
    void addElement(int row, int col, int value) {
        if (row < 0 || row >= rows || col < 0 || col >= columns) {
            std::cerr << "Error: Attempting to add element outside matrix boundaries." << std::endl;
            return;
        }

        Node* newNode = new Node(row, col, value);
        if (!head || (row < head->row) || (row == head->row && col < head->col)) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next && (current->next->row < row || (current->next->row == row && current->next->col < col))) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        ++capacity;
    }

   
    void print() const {
        if (getCapacity() == 0)
        {
            std::cout << "Empty matrix.";
        }
        if (getSize() <= 400 && getCapacity() * 100 > getSize() * 70) {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    Node* current = head;
                    bool found = false;
                    while (current) {
                        if (current->row == i && current->col == j) {
                            std::cout << current->value << " ";
                            found = true;
                            break;
                        }
                        current = current->next;
                    }
                    if (!found) {
                        std::cout << "0 ";
                    }
                }
                std::cout << std::endl;
            }
        }
        else {
            Node* current = head;
            while (current) {
                std::cout << "Row: " << current->row << " Col: " << current->col << " Val: " << current->value << std::endl;
                current = current->next;
            }
        }
    }

    int getElement(int row, int column) const {
        Node* current = head;
        while (current) {
            if (current->row == row && current->col == column) {
                return current->value;
            }
            current = current->next;
        }
        return 0;
    }
    int getCapacity() const
    {
        return capacity;
    }
   friend SparseMatrix multiplyByScalar(const SparseMatrix& matrix, int scalar) {
        SparseMatrix result(matrix.rows, matrix.columns);
        Node* current = matrix.head;
        while (current) {
            result.addElement(current->row, current->col, current->value * scalar);
            current = current->next;
        }
        return result;
    }
   
};
