#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T) {
        int n = T.size();
        vector<int> res(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                int index = stk.top();
                stk.pop();
                res[index] = i - index;
            }
            stk.push(i);
        }
        return res;
    }
};