#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);
    }
};