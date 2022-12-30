#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for (char c: expression) {
            if (c == ',') continue;
            else if (c != ')') stk.push(c);
            else {
                int t = 0, f = 0;
                while (stk.top() != '(') {
                    if (stk.top() == 't') t++;
                    else if (stk.top() == 'f') f++;
                    stk.pop();
                }
                stk.pop();
                char op = stk.top();
                stk.pop();
                if (op == '!') {
                    stk.push(t == 0 ? 't' : 'f');
                } else if (op == '&') {
                    stk.push(f == 0 ? 't' : 'f');
                } else {
                    stk.push(t >= 1 ? 't' : 'f');
                }
            }
        }
        return stk.top() == 't';
    }
};