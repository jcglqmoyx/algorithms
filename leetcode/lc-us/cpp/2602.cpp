#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries) {
        int n = (int) nums.size(), m = (int) queries.size();
        sort(nums.begin(), nums.end());
        long long s[n + 2];
        memset(s, 0, sizeof s);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        vector<long long> res(m);
        for (int i = 0; i < m; i++) {
            long long q = queries[i];
            int t = (int) (lower_bound(nums.begin(), nums.end(), q) - nums.begin()) + 1;
            res[i] = (t - 1) * q - s[t - 1] + s[n] - s[t - 1] - (n - t + 1) * q;
        }
        return res;
    }
};