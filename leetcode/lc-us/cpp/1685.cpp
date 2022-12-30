#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> ans(n);
        vector<int> sum(nums);
        for (int i = 1; i < n; i++) sum[i] += sum[i - 1];
        for (int i = 0; i < n; i++) {
            if (i == 0) ans[i] = sum.back() - sum[0] - (n - 1) * sum[0];
            else if (i == n - 1) ans[i] = nums[i] * (n - 1) - sum[i - 1];
            else ans[i] = nums[i] * i - sum[i - 1] + sum.back() - sum[i] - nums[i] * (n - 1 - i);
        }
        return ans;
    }
};