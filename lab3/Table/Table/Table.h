#pragma once
#pragma once
#include <iostream>
#include <string>

class Table {
public:
    struct KeyNode {
        int key;
        int index;
    };
    struct ValueNode {
        std::string value;
        int index;
    };

    Table();
    Table(int start_size);
    ~Table();

    int GetQuantity();
    Table& PutPair(int key, const std::string& value);
    Table& EraseByKey(int key);
    bool CheckByKey(int key);
    int GetKey(const std::string& value);
    std::string& GetValue(int key);
    int* GetKeys();
    std::string* GetValues();
    void PrintPair(int key, const std::string& value);
    void PrintTable();
    std::string& operator[](int index);

private:
    void Resize();
    void Remove();
    bool FindKeyIndex(int key, int& index);
    void SavePair(int key, const std::string& value, int ind);

    int size;
    int quantity;
    int position;
    KeyNode* keys;
    ValueNode* values;
};