#include "BitSet.h"

BitSet::BitSet() : bits(0) {}

void BitSet::add(int index) {
    if (index >= 0 && index < size) {
        bits |= (1 << index);
    }
    else {
        std::cerr << "Invalid index\n";
    }
}

void BitSet::remove(int index) {
    if (index >= 0 && index < size) {
        bits &= ~(1 << index);
    }
    else {
        std::cerr << "Invalid index\n";
    }
}

bool BitSet::contains(int index) const {
    return (bits & (1 << index)) != 0;
}

void BitSet::print() const {
    for (int i = size - 1; i >= 0; --i) {
        std::cout << ((bits & (1 << i)) ? '1' : '0');
    }
    std::cout << std::endl;
}

BitSet BitSet::merge(const BitSet& other) const
{
    BitSet result;
    result.bits = bits | other.bits;
    return result;
}
