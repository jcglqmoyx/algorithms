#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = (int) temperatures.size();
        vector<int> res(n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) stk.pop();
            if (stk.empty()) res[i] = 0;
            else res[i] = stk.top() - i;
            stk.push(i);
        }
        return res;
    }
};