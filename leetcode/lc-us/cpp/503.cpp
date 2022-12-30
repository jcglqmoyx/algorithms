#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = (int) nums.size();
        for (int i = 0; i < n - 1; i++) nums.push_back(nums[i]);
        vector<int> res(n);
        stack<int> stk;
        for (int i = 0; i < n + n - 1; i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                if (stk.top() < n) res[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            if (stk.top() < n) res[stk.top()] = -1;
            stk.pop();
        }
        return res;
    }
};