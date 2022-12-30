#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int> &nums) {
        int n = (int) nums.size(), m = n >> 1;
        vector<vector<int>> f(m + 1), g(m + 1);
        for (int i = 0; i < 1 << m; i++) {
            int sum = 0, cnt = 0;
            for (int j = 0; j < m; j++) {
                if (i >> j & 1) {
                    sum += nums[j];
                    cnt++;
                } else {
                    sum -= nums[j];
                }
            }
            f[cnt].push_back(sum);
        }
        for (auto &v: f) sort(v.begin(), v.end());
        int res = INT32_MAX;
        for (int i = 0; i < 1 << m; i++) {
            int sum = 0, cnt = 0;
            for (int j = m; j < n; j++) {
                if (i >> (j - m) & 1) {
                    sum += nums[j];
                    cnt++;
                } else {
                    sum -= nums[j];
                }
            }
            auto &v = f[m - cnt];
            int target = -sum;
            int idx = (int) (lower_bound(v.begin(), v.end(), target) - v.begin());
            if (idx < v.size()) res = min(res, abs(v[idx] + sum));
            else res = min(res, abs(v.back() + sum));
        }
        return res;
    }
};