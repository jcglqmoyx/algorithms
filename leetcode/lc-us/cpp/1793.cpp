#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int> &nums, int k) {
        int n = (int) nums.size();
        stack<int> stk;
        vector<int> l(n, -1), r(n, n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            if (!stk.empty()) l[i] = stk.top();
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            if (!stk.empty()) r[i] = stk.top();
            stk.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (l[i] < k && r[i] > k) res = max(res, (r[i] - l[i] - 1) * nums[i]);
        }
        return res;
    }
};