#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int> &nums) {
        using LL = long long;
        int n = (int) nums.size();
        vector<vector<LL>> f(n + 1, vector<LL>(2, -1e9));
        LL res = INT64_MIN;
        for (int i = 1; i <= n; i++) {
            f[i][0] = max((LL) nums[i - 1], f[i - 1][1] + nums[i - 1]);
            f[i][1] = f[i - 1][0] - nums[i - 1];
            res = max(res, max(f[i][0], f[i][1]));
        }
        return res;
    }
};