#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int validSubarraySize(vector<int> &nums, int threshold) {
        int n = (int) nums.size();
        vector<int> l(n), r(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            if (!stk.empty()) l[i] = stk.top() + 1;
            else l[i] = 0;
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            if (!stk.empty()) r[i] = stk.top() - 1;
            else r[i] = n - 1;
            stk.push(i);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > threshold / (r[i] - l[i] + 1)) {
                return r[i] - l[i] + 1;
            }
        }
        return -1;
    }
};