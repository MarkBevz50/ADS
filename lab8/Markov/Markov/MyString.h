#pragma once
#include <iostream>
#include <vector>
using namespace std;
class MyString {
private:
    std::vector<char> data;

public:
    MyString();
    MyString(const char* str);
    size_t length() const;
    size_t find(const MyString& sub_str) const;
    void replace(size_t pos, size_t len, const MyString& str);
    MyString substr(size_t pos, size_t len) const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);

};

struct Rule {
    MyString left;
    MyString right;
};
MyString apply_rules(const MyString& input, const vector<Rule>& rules);