#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumTop(vector<int> &nums, int k) {
        int n = (int) nums.size();
        if (k == 0) return nums[0];
        if (n == 1 && k & 1) return -1;
        if (k > n) return *max_element(nums.begin(), nums.end());

        int res = -1;
        int i = 0;
        for (; i < min(n, k - 1); i++) {
            res = max(res, nums[i]);
        }
        if (i + 1 < n) res = max(res, nums[i + 1]);
        return res;
    }
};