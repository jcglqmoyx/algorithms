#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int validSubarrays(vector<int> &nums) {
        stack<int> stk;
        int n = (int) nums.size();
        vector<int> f(n, n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                f[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += f[i] - i;
        }
        return res;
    }
};