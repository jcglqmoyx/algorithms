#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDifference(vector<int> &nums) {
        int n = (int) nums.size();
        if (n <= 4) return 0;
        sort(nums.begin(), nums.end());
        int res = 2e9;
        for (int i = 0; i <= 3; i++) {
            int j = 3 - i;
            res = min(res, nums[n - 1 - j] - nums[i]);
        }
        return res;
    }
};