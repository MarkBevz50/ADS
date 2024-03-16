#pragma once
#include <iostream>

class BitSet {
private:
    static const int size = 64;
    unsigned int bits;

public:
    BitSet();
    void add(int index);
    void remove(int index);
    bool contains(int index) const;
    void print() const;
    BitSet merge(const BitSet& other) const;
};
