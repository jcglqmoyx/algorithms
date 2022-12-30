#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string parseTernary(string expression) {
        stack<char> stk;
        for (int i = (int) expression.size() - 1; i >= 0; i--) {
            char c = expression[i];
            if (c == ':') continue;
            if (isalnum(c)) stk.push(c);
            else if (c == '?') {
                i--;
                char ch = expression[i];
                char x = stk.top();
                stk.pop();
                char y = stk.top();
                stk.pop();
                if (ch == 'T') stk.push(x);
                else if (ch == 'F') stk.push(y);
            }
        }
        string s;
        s += stk.top();
        return s;
    }
};