#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int mx = nums[0], mn = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int maxF = mx, minF = mn;
            mx = max(maxF * nums[i], max(nums[i], minF * nums[i]));
            mn = min(minF * nums[i], min(nums[i], maxF * nums[i]));
            res = max(res, mx);
        }
        return res;
    }
};