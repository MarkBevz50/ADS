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
            // ����� ��� ��������� �������
            vector<Rule> rules = {
                {"+|", "|"},
                // �������� �������
            };

            string input("|||+||");

            string result = apply_rules(input, rules);

            Assert::AreEqual(string("|||||"), result);
        }

        TEST_METHOD(TestMarkovAlgorithm2)
        {
            
            vector<Rule> rules = {
                
                {"|-|", "-"},
                // �������� �������
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
                
                // �������� �������
            };

            string input("abcirkrtc");

            string result = apply_rules(input, rules);

            Assert::AreEqual(string("I love you"), result);
        }

        TEST_METHOD(TestMarkovAlgorithmNoRuleApplied)
        {
            // ���� ��� ��������� �������, ���� ����� ������� �� �����������
            vector<Rule> rules = {
                {"+|", "|+"},
                {"-|", " "},
                {"abc", "def"},
            };

            string input("xyz");

            string result = apply_rules(input, rules);

            Assert::AreEqual(string("xyz"), result); // ���������, �� ����� ���� ����� ��, �� ������� �����
        }

      
	};
}
