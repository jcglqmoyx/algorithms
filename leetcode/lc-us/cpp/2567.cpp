#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeSum(vector<int> &nums) {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        return min(nums[n - 1] - nums[2], min(nums[n - 2] - nums[1], nums[n - 3] - nums[0]));
    }
};