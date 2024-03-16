
#include <iostream>
#include <stack>
#include <iomanip>
#include "Stack.h"

int main() {
    std::stack<int> Case;
    Stack Case2;
    int size;
    int count = 0;
    int number;

    std::cout << "How many numbers do you want in your stack?: \n" ;
    std::cin >> size;

    while (count != size) {
        std::cin >> number;
        Case.push(number);
        Case2.Push(number);
        ++count;
    }
    



    while (!Case.empty()) {
        std::cout << "Is STL stack empty? [" << std::boolalpha << Case.empty() << "]\n";
       std::cout << Case.top() << std::endl;
        std::cout << "Is My stack empty? [" << std::boolalpha << Case2.isEmpty() << "]\n";
       if(size )
        std::cout << Case2.Top() << std::endl;
        
        Case.pop();
        Case2.Pop();
        --count;
    }

    std::cout << "Is STL stack empty? [" << std::boolalpha << Case.empty() << ']';
    std::cout << "Is My stack empty? [" << std::boolalpha << Case2.isEmpty() << "]\n";


    return 0;
}
