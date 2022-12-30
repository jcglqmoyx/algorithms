#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 1e9;
        for (int i = 0; i + k - 1 < nums.size(); i++) {
            result = min(result, nums[i + k - 1] - nums[i]);
        }
        return result;
    }
};