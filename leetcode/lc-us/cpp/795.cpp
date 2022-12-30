#include <bits/stdc++.h>

using namespace std;

class Solution {
    long long calc(vector<int> &nums, int k) {
        long long res = 0;
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > k) continue;
            int j = i + 1;
            while (j < n && nums[j] <= k) j++;
            int len = j - i;
            res += (long long) len * (len + 1) / 2;
            i = j;
        }
        return res;
    }

public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
        return calc(nums, right) - calc(nums, left - 1);
    }
};