#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int res = nums.back() - nums.front();
        for (int i = 0; i + 1 < nums.size(); i++) {
            int mx = max(nums[i] + k, nums.back() - k);
            int mn = min(nums[0] + k, nums[i + 1] - k);
            res = min(res, mx - mn);
        }
        return res;
    }
};