#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res;
        stack<int> stk;
        for (char c: s) {
            if (res.empty() || res.back() != c) stk.push(1);
            else stk.top()++;
            res.push_back(c);
            if (stk.top() >= k) {
                stk.top() -= k;
                if (!stk.top()) stk.pop();
                for (int i = 0; i < k; i++) res.pop_back();
            }
        }
        return res;
    }
};