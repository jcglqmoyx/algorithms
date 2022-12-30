#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int purchasePlans(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        long res = 0;
        int n = (int) nums.size();
        if (n == 2) {
            if (nums[0] + nums[1] <= target) return 1; else return 0;
        }
        int mod = 1000000007;

        for (int i = 0; i < n - 1; i++) {
            int p = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
            if (p > i)
                res = res + p - i - 1;
            res %= mod;
        }
        return (int) res;
    }
};