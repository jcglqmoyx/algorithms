#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int res = 0;
        for (int i = 0, start = -1; i < s.size(); i++) {
            if (s[i] == '(') stk.push(i);
            else {
                if (!stk.empty()) {
                    stk.pop();
                    if (!stk.empty()) {
                        res = max(res, i - stk.top());
                    } else {
                        res = max(res, i - start);
                    }
                } else {
                    start = i;
                }
            }
        }
        return res;
    }
};