#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 1;
        long long K = k;
        for (int i = 0, j = 1; j < nums.size(); j++) {
            K -= (long long) (j - i) * (nums[j] - nums[j - 1]);
            while (K < 0) K += nums[j] - nums[i], i++;
            res = max(res, j - i + 1);
        }
        return res;
    }
};