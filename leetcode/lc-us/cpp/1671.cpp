#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int> &nums) {
        int res = INT32_MIN, n = (int) nums.size();
        vector<int> f(n), g(n);
        vector<int> seq;
        for (int i = 0; i < n; i++) {
            if (seq.empty() || nums[i] > seq.back()) seq.push_back(nums[i]);
            else {
                auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
                *it = nums[i];
            }
            f[i] = (int) seq.size();
        }
        seq.clear();
        for (int i = n - 1; ~i; i--) {
            if (seq.empty() || nums[i] > seq.back()) seq.push_back(nums[i]);
            else {
                auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
                *it = nums[i];
            }
            g[i] = (int) seq.size();
        }
        for (int i = 1; i < n - 1; i++) {
            if (f[i] > 1 && g[i] > 1) {
                res = max(res, f[i] + g[i] - 1);
            }
        }
        return n - res;
    }
};