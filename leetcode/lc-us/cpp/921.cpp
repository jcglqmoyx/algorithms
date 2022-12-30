#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int add = 0;
        for (char c: s) {
            if (c == '(') {
                stk.push(c);
            } else {
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                } else {
                    add++;
                }
            }
        }
        add += (int) stk.size();
        return add;
    }
};