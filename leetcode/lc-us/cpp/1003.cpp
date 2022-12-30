#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string stk;
        for (char c: s) {
            stk.push_back(c);
            while (stk.size() >= 3 && stk.substr(stk.size() - 3) == "abc") {
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
            }
        }
        return stk.empty();
    }
};