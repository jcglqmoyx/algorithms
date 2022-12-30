#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int> &nums) {
        int n = (int) nums.size();
        int mn = INT32_MAX, mx = INT32_MIN, min_idx = 0, max_idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < mn) mn = nums[i], min_idx = i;
            if (nums[i] > mx) mx = nums[i], max_idx = i;
        }
        int res = min(max(min_idx, max_idx) + 1, max(n - min_idx, n - max_idx));
        if (min_idx > max_idx) swap(min_idx, max_idx);
        res = min(res, min_idx + 1 + n - max_idx);
        return res;
    }
};