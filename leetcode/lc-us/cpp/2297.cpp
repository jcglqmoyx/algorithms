#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minCost(vector<int> &nums, vector<int> &costs) {
        using LL = long long;
        int n = (int) nums.size();
        stack<int> stk1, stk2;
        vector<int> f1(n), f2(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk1.empty() && nums[stk1.top()] < nums[i]) stk1.pop();
            if (stk1.empty()) f1[i] = i;
            else f1[i] = stk1.top();
            stk1.push(i);

            while (!stk2.empty() && nums[stk2.top()] >= nums[i]) stk2.pop();
            if (stk2.empty()) f2[i] = i;
            else f2[i] = stk2.top();
            stk2.push(i);
        }
        vector<LL> f(n, INT64_MAX / 2);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            f[f1[i]] = min(f[f1[i]], f[i] + costs[f1[i]]);
            f[f2[i]] = min(f[f2[i]], f[i] + costs[f2[i]]);
        }
        return f[n - 1];
    }
};