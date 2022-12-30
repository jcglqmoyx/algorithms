#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int n = (int) nums.size();
        int res = 0;
        int mx = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] != mx) continue;
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) j++;
            res = max(res, j - i);
            i = j - 1;
        }
        return res;
    }
};