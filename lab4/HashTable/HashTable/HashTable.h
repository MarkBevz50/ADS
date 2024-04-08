#pragma once
#include <iostream>
#include <string>

class HashTable {
public:
    HashTable();
    HashTable(int initial_capacity);
    ~HashTable();

    void PutPair(int key, const std::string& value);
    void EraseByKey(int key);
    bool CheckByKey(int key);
    int GetKey(const std::string& value);
    std::string& GetValue(int key);
    int* GetKeys(int& size);
    std::string* GetValues(int& size);
    void PrintPair(int key, const std::string& value);
    void PrintTable();
    std::string& operator[](int key);

private:
    struct Node {
        int key;
        std::string value;
        Node* next;
        Node(int k, const std::string& v) : key(k), value(v), next(nullptr) {}
    };

    Node** buckets;
    size_t size;
    size_t capacity;

    size_t HashFunction(int key);
    void Resize();
};
