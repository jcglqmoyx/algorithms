#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalSteps(vector<int> &nums) {
        int res = 0, n = (int) nums.size(), f[n];
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            while (!stk.empty() && nums[stk.top()] <= nums[i]) {
                cur = max(cur, f[stk.top()]);
                stk.pop();
            }
            if (!stk.empty()) {
                f[i] = cur + 1;
                res = max(res, f[i]);
            }
            stk.push(i);
        }
        return res;
    }
};