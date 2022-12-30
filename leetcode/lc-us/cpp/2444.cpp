#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK) {
        int mx = -1, mn = -1, idx = -1;
        long long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == minK) mn = i;
            if (nums[i] == maxK) mx = i;
            if (nums[i] < minK || nums[i] > maxK) idx = i;
            res += max(0, min(mn, mx) - idx);
        }
        return res;
    }
};