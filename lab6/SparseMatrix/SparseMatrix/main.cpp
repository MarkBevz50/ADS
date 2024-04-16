#include <iostream>
#include <vector>
#include <string>
#include "SparseMatrix.h"
int main() {
    int rows, columns;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> columns;
    SparseMatrix matrix(rows, columns);
    while (true) {
        int row = 0, column = 0, value = 0;
        std::cout << "Enter row, column, and value (or 'stop' to end): ";
        std::string input;
        std::cin >> input;
        if (input == "stop") {
            break;
        }
        row = std::stoi(input);
        std::cin >> column >> value;
        matrix.addElement(row, column, value);
    }
    matrix.print();
    std::cout << "Enter multiplyer for your matrix:";
    int coef;
    std::cin >> coef;
    SparseMatrix result = multiplyByScalar(matrix, coef);
    result.print();
    return 0;
}