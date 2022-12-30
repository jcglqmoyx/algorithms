#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int n = (int) nums.size();
        int res = INT32_MIN, sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum <= 0) sum = nums[i];
            else sum += nums[i];
            res = max(res, sum);
        }
        sum = 0;
        for (int i = n - 1; i < (n << 1) - 1; i++) {
            if (sum <= 0) sum = nums[i % n];
            else sum += nums[i % n];
            res = max(res, sum);
        }
        int mn = INT32_MAX;
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum >= 0) sum = nums[i];
            else sum += nums[i];
            mn = min(mn, sum);
        }
        sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == mn) return res;
        return max(res, sum - mn);
    }
};