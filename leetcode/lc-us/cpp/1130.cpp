#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int> &arr) {
        stack<int> stk;
        int res = 0;
        for (int x: arr) {
            while (!stk.empty() && stk.top() <= x) {
                int y = stk.top();
                stk.pop();
                if (stk.empty() || stk.top() > x) res += y * x;
                else res += stk.top() * y;
            }
            stk.push(x);
        }
        while (stk.size() > 1) {
            int x = stk.top();
            stk.pop();
            res += x * stk.top();
        }
        return res;
    }
};