#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int> &nums) {
        int res = 1;
        for (int mask = 0, l = 0, r = 0; r < nums.size(); r++) {
            while (mask & nums[r]) {
                mask ^= nums[l++];
            }
            mask |= nums[r];
            res = max(res, r - l + 1);
        }
        return res;
    }
};