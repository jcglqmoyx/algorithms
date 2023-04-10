#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {{')', '('},
                                         {']', '['},
                                         {'}', '{'}};
        stack<char> stk;
        for (char c: s) {
            if (map.count(c)) {
                if (stk.empty() || stk.top() != map[c]) return false;
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};