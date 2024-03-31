
#include "table.h"

Table::Table() : size(0), quantity(0), position(0), keys(nullptr), values(nullptr) {}

Table::Table(int start_size) : size(start_size), quantity(0), position(0) {
    keys = new KeyNode[size];
    values = new ValueNode[size];
}

Table::~Table() {
    delete[] keys;
    delete[] values;
}

int Table::GetQuantity() {
    return quantity;
}


Table& Table::PutPair(int key, const std::string& value) {
    int in;
    if (FindKeyIndex(key, in))
        throw std::runtime_error("Key already exists in the table.");
    else
        SavePair(key, value, in);
    return *this;
}
//Table& Table::EraseByKey(int key) {
//    int i;
//    if (quantity == 0 || !FindKeyIndex(key, i)) {
//        return *this;
//    }
//    values[keys[i].index].index = -1;
//    keys[i].index = -1; 
//    for (int j = i; j < quantity - 1; j++) {
//        keys[j] = keys[j + 1];
//        values[keys[j].index].index = keys[j].index;
//    }
//    --position;
//    --quantity;
//    return *this;
//}
Table& Table::EraseByKey(int key) {
    int i;
    if (quantity == 0) {
        std::cerr << "Error: Key " << key << " not found in the table, table is empty ." << std::endl;
        return *this;
    }
    else if (!FindKeyIndex(key, i)) {
        std::cerr << "Error: Key " << key << " not found in the table ." << std::endl;
        return *this;
    }
     
    values[keys[i].index].index = -1;
    keys[i].index = -1;
    for (int j = i; j < quantity - 1; j++) {
        keys[j] = keys[j + 1];
        values[keys[j].index].index = keys[j].index;
    }
    --position;
    --quantity;
    return *this;
}

bool Table::CheckByKey(int key) {
    for (int i = 0; i < position; ++i)
        if (keys[i].index != -1 && keys[i].key == key)
        {
            return true;
        }
    return false;
}

int Table::GetKey(const std::string& value) {
    for (int i = 0; i < position; ++i) {
        if (values[i].index != -1 && values[i].value == value) {
            return keys[values[i].index].key;
        }
    }
    return -1;
}

std::string& Table::GetValue(int key) {
    for (int i = 0; i < position; ++i) {
        if (keys[i].index != -1 && keys[i].key == key)
            return values[keys[i].index].value;
    }
    static std::string empty = " ";
    return empty;
}

int* Table::GetKeys() {
    int* ks = new int[quantity];
    for (int i = 0; i < quantity; ++i) {
        ks[i] = keys[i].key;
    }
    return ks;
}

std::string* Table::GetValues() {
    std::string* vs = new std::string[quantity];
    for (int i = 0, j = 0; i < position; ++i)
        if (values[i].index != -1)
            vs[j++] = values[i].value;
    return vs;
}

void Table::PrintPair(int key, const std::string& value) {
    std::cout << value << "'s key is " << key << std::endl;
}

void Table::PrintTable() {
    if (quantity == 0)
        std::cout << "table is empty" << std::endl;
    else
        for (int i = 0; i < quantity; ++i)
            std::cout << keys[i].key << " ---> " << values[keys[i].index].value << std::endl;
}

std::string& Table::operator[](int index) {
    if (index < 0 || index >= size) {
        static std::string empty = " ";
        return empty;
    }
    return values[index].value;
}

void Table::Resize() {
    int new_size = size + 10;
    KeyNode* new_keys = new KeyNode[new_size];
    ValueNode* new_values = new ValueNode[new_size];
    for (int i = 0; i < size; i++) {
        new_keys[i] = keys[i];
        new_values[i] = values[i];
    }
    delete[] keys;
    keys = new_keys;
    delete[] values;
    values = new_values;
    size = new_size;
}

void Table::Remove() {
    while (values[position - 1].index == -1)
        --position;
    for (int i = 0; i < position; i++) {
        if (values[i].index == -1) {
            for (int j = 0; j < position - 1; ++j) {
                values[j] = values[j + 1];
                keys[values[j].index].index = j;
            }
            --position;
        }
    }
}

bool Table::FindKeyIndex(int key, int& index) {
    if (quantity == 0) {
        index = 0;
        return false;
    }
    int a = 0;
    int b = quantity - 1;
    while (a <= b) {
        int c = (a + b) / 2;
        if (key == keys[c].key) {
            index = c;
            return true;
        }
        if (key < keys[c].key)
            b = c - 1;
        else
            a = c + 1;
    }
    index = a;
    return false;
}

void Table::SavePair(int key, const std::string& value, int ind) {
    if (quantity == size)
        Resize();
    if (position == size)
        Remove();
    for (int j = quantity; j > ind; --j) {
        keys[j] = keys[j - 1];
        values[keys[j].index].index = j;
    }
    keys[ind].key = key; keys[ind].index = position;
    values[position].value = value;
    values[position].index = ind;
    ++quantity;
    ++position;
}