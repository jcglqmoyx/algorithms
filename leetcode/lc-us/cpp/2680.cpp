#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumOr(vector<int> &nums, int k) {
        int n = (int) nums.size();
        int suf[n + 1];
        suf[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = nums[i] | suf[i + 1];
        }
        long long res = 0;
        for (int i = 0, pre = 0; i < n; i++) {
            res = max(res, pre | nums[i] * 1LL << k | suf[i + 1]);
            pre |= nums[i];
        }
        return res;
    }
};