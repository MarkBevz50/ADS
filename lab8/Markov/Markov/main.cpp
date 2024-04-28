#include <iostream>
#include <string>
#include <vector>
#include "MyString.h"


int main() {
    vector<Rule> rules = {
        /*{"ab", "c"},
        {"bc", "d"},
        {"cd", "e"},
        {"cccc", "I"}*/
        {"+|", "|"},  // Унарне додавання
        {"|-|", "-"},
        {"-", "" },        // Унарне віднімання
        {"aa" ,"b"},
        {"aaa", "c"},
        {"abc", "I "},
        {"irk", "love "},
        {"rtc", "you"}
    };
    MyString input = "||||||-||";
    MyString input2 = "abcirkrtc";
    MyString input3 = "||||||+||";
    MyString result = apply_rules(input, rules);
    MyString result2 = apply_rules(input2, rules);
    MyString result3 = apply_rules(input3, rules);
    cout << "Original string: " << input << endl;
    cout << "Result after applying Markov algorithm: " << result << endl;
    cout << "Original string: " << input2 << endl;
    cout << "Result after applying Markov algorithm: " << result2 << endl;
    cout << "Original string: " << input3 << endl;
    cout << "Result after applying Markov algorithm: " << result3 << endl;
    MyString input5 = "aaaaa";
    MyString result5 = apply_rules(input5, rules);
    std::cout << result5;
    
}