#include "MyString.h"

MyString::MyString() {}

MyString::MyString(const char* str) {
    while (*str) {
        data.push_back(*str);
        ++str;
    }
}

size_t MyString::length() const {
    return data.size();
}

size_t MyString::find(const MyString& sub_str) const {
    for (size_t i = 0; i < data.size(); ++i) {
        bool found = true;
        for (size_t j = 0; j < sub_str.length(); ++j) {
            if (i + j >= data.size() || data[i + j] != sub_str.data[j]) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return static_cast<size_t>(-1);
}

void MyString::replace(size_t pos, size_t len, const MyString& str) {
    data.erase(data.begin() + pos, data.begin() + pos + len);
    data.insert(data.begin() + pos, str.data.begin(), str.data.end());
}

MyString MyString::substr(size_t pos, size_t len) const {
    MyString sub;
    for (size_t i = pos; i < pos + len && i < data.size(); ++i) {
        sub.data.push_back(data[i]);
    }
    return sub;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    for (char ch : str.data) {
        os << ch;
    }
    return os;
}

MyString apply_rules(const MyString& input, const vector<Rule>& rules)
{
        MyString output = input;
        bool rule_applied = true;

        while (rule_applied) {
            rule_applied = false;

            for (const auto& rule : rules) {
                size_t pos = output.find(rule.left);
                if (pos != string::npos) {
                    output.replace(pos, rule.left.length(), rule.right);
                    rule_applied = true;
                    break;
                }
            }
        }

        return output;
    
}

