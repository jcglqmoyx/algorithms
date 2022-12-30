#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string str;
        for (char c: s) {
            if (c == '(') {
                stk.push(str);
                str.clear();
            } else if (c == ')') {
                reverse(str.begin(), str.end());
                string t;
                if (!stk.empty()) {
                    t.append(stk.top());
                    stk.pop();
                }
                t.append(str);
                str = t;
            } else {
                str.push_back(c);
            }
        }
        return str;
    }
};