#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPairSum(vector<int> &nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = (int) nums.size() - 1;
        while (l < r) {
            res = max(res, nums[l] + nums[r]);
            l++;
            r--;
        }
        return res;
    }
};