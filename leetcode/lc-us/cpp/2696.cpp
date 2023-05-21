#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (char c: s) {
            if (!stk.empty() && (stk.top() == 'A' && c == 'B' || stk.top() == 'C' && c == 'D'))stk.pop();
            else stk.push(c);
        }
        return (int) stk.size();
    }
};