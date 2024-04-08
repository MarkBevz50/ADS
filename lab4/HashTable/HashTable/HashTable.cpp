#include "HashTable.h"
HashTable::HashTable() : size(0), capacity(10) {
    buckets = new Node * [capacity];
    for (size_t i = 0; i < capacity; ++i) {
        buckets[i] = nullptr;
    }
}

HashTable::HashTable(int initial_capacity) : size(0), capacity(initial_capacity) {
    buckets = new Node * [capacity];
    for (size_t i = 0; i < capacity; ++i) {
        buckets[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for (size_t i = 0; i < capacity; ++i) {
        Node* current = buckets[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] buckets;
}

void HashTable::PutPair(int key, const std::string& value) {
    size_t index = HashFunction(key);
    Node* newNode = new Node(key, value);
    newNode->next = buckets[index];
    buckets[index] = newNode;
    ++size;

    // Resize if load factor exceeds 0.75
    if (static_cast<double>(size) / capacity > 0.75) {
        Resize();
    }
}

void HashTable::EraseByKey(int key) {
    size_t index = HashFunction(key);
    Node* current = buckets[index];
    Node* prev = nullptr;
    if (size == 0)
    {
        std::cerr << "There is nothing to delete, empty table";
    }
    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                buckets[index] = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            --size;
            return;
        }
        prev = current;
        current = current->next;
    }

    std::cerr << "Error: Key " << key << " not found in the table." << std::endl;
}

bool HashTable::CheckByKey(int key) {
    size_t index = HashFunction(key);
    Node* current = buckets[index];
    while (current != nullptr) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int HashTable::GetKey(const std::string& value) {
    for (size_t i = 0; i < capacity; ++i) {
        Node* current = buckets[i];
        while (current != nullptr) {
            if (current->value == value) {
                return current->key;
            }
            current = current->next;
        }
    }
    return -1;
}

std::string& HashTable::GetValue(int key) {
    size_t index = HashFunction(key);
    Node* current = buckets[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    static std::string empty = " ";
    return empty;
}

int* HashTable::GetKeys(int& size) {
    int* keys = new int[size];
    size_t index = 0;
    for (size_t i = 0; i < capacity; ++i) {
        Node* current = buckets[i];
        while (current != nullptr) {
            keys[index++] = current->key;
            current = current->next;
        }
    }
    size = index;
    return keys;
}

std::string* HashTable::GetValues(int& size) {
    std::string* values = new std::string[size];
    size_t index = 0;
    for (size_t i = 0; i < capacity; ++i) {
        Node* current = buckets[i];
        while (current != nullptr) {
            values[index++] = current->value;
            current = current->next;
        }
    }
    size = index;
    return values;
}

void HashTable::PrintPair(int key, const std::string& value) {
    std::cout << value << "'s key is " << key << std::endl;
}

void HashTable::PrintTable() {
    for (size_t i = 0; i < capacity; ++i) {
        Node* current = buckets[i];
        while (current != nullptr) {
            std::cout << current->key << " ---> " << current->value << std::endl;
            current = current->next;
        }
    }
}

std::string& HashTable::operator[](int key) {
    size_t index = HashFunction(key);
    Node* current = buckets[index];
    while (current != nullptr) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    static std::string empty = " ";
    return empty;
}

size_t HashTable::HashFunction(int key) {
    return key % capacity;
}

void HashTable::Resize() {
    size_t new_capacity = capacity * 2;
    Node** new_buckets = new Node * [new_capacity];
    for (size_t i = 0; i < new_capacity; ++i) {
        new_buckets[i] = nullptr;
    }

    for (size_t i = 0; i < capacity; ++i) {
        Node* current = buckets[i];
        while (current != nullptr) {
            size_t index = HashFunction(current->key);
            Node* newNode = new Node(current->key, current->value);
            newNode->next = new_buckets[index];
            new_buckets[index] = newNode;
            current = current->next;
        }
    }

    for (size_t i = 0; i < capacity; ++i) {
        Node* current = buckets[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    delete[] buckets;
    buckets = new_buckets;
    capacity = new_capacity;
}