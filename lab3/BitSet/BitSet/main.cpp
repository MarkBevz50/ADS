#include <iostream>
#include <iomanip>
#include "BitSet.h"

int main() {
    std::cout << "Basic set: " << '\n';
    BitSet mySet;
    mySet.print();
    std::cout << "Added two elements:" << '\n';
    mySet.add(5);
    mySet.add(7);
    mySet.print();
    std::cout << "Contains 5: " << std::boolalpha<<mySet.contains(5) << std::endl;
    std::cout << "Contains 7: " << std::boolalpha<<mySet.contains(7)  << std::endl;
    mySet.remove(5);
    mySet.print();
    std::cout << "Contains 5: " << std::boolalpha << mySet.contains(5) << std::endl;
    std::cout << "Contains 7: " << std::boolalpha << mySet.contains(7) << std::endl;
    BitSet set1, set2;

    set1.add(1);
    set1.add(3);
    set1.add(5);

    set2.add(3);
    set2.add(4);
    set2.add(6);

    BitSet mergedSet = set1.merge(set2);

    std::cout << "Set 1: ";
    set1.print();

    std::cout << "Set 2: ";
    set2.print();

    std::cout << "Merged Set: ";
    mergedSet.print();
    BitSet set11, set22;


    return 0;
}