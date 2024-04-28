#include "pch.h"
#include "CppUnitTest.h"
#include "../Markov/MyString.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MarkovAndStringTest
{
	TEST_CLASS(MarkovAndStringTest)
	{
	public:
        
        TEST_METHOD(TestMarkovAlgorithm)
        {
            // Тести для алгоритму Маркова
            vector<Rule> rules = {
                {"+|", "|"},
                // Додаткові правила
            };

            string input("|||+||");

            string result = apply_rules(input, rules);

            Assert::AreEqual(string("|||||"), result);
        }

        TEST_METHOD(TestMarkovAlgorithm2)
        {
            
            vector<Rule> rules = {
                
                {"|-|", "-"},
                // Додаткові правила
            };

            string input("|||-||");

            string result = apply_rules(input, rules);

            Assert::AreEqual(string("|-"), result);
        }
        TEST_METHOD(TestMarkovAlgorithmMultRul)
        {

            vector<Rule> rules = {

                {"abc", "I "},
                {"irk", "love "},
                {"rtc", "you"}
                
                // Додаткові правила
            };

            string input("abcirkrtc");

            string result = apply_rules(input, rules);

            Assert::AreEqual(string("I love you"), result);
        }

        TEST_METHOD(TestMarkovAlgorithmNoRuleApplied)
        {
            // Тест для алгоритму Маркова, коли жодне правило не застосовано
            vector<Rule> rules = {
                {"+|", "|+"},
                {"-|", " "},
                {"abc", "def"},
            };

            string input("xyz");

            string result = apply_rules(input, rules);

            Assert::AreEqual(string("xyz"), result); // Очікується, що вихід буде таким же, як вхідний рядок
        }

      
	};
}
