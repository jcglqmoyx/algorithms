#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        string buttons[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (char digit: digits) {
            if (combinations.empty()) {
                for (char c: buttons[digit - 48]) {
                    string s;
                    s.push_back(c);
                    combinations.push_back(s);
                }
            } else {
                for (int i = (int) combinations.size() - 1; i >= 0; i--) {
                    string combination = combinations.front();
                    combinations.erase(combinations.begin());
                    for (char c: buttons[digit - 48]) {
                        string str = combination + c;
                        combinations.push_back(str);
                    }
                }
            }
        }
        return combinations;
    }
};