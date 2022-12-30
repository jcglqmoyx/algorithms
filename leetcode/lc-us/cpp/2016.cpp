#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int> &nums) {
        int res = -1;
        int mn = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res = max(res, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return res <= 0 ? -1 : res;
    }
};