#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int> &nums, int k) {
        const int MOD = 1e9 + 7;
        if (accumulate(nums.begin(), nums.end(), 0LL) < 2 * k) return 0;
        int f[k];
        memset(f, 0, sizeof f);
        f[0] = 1;
        int res = 1;
        for (int x: nums) {
            res = res * 2 % MOD;
            for (int j = k - 1; j >= x; j--) {
                f[j] = (f[j] + f[j - x]) % MOD;
            }
        }
        for (int x: f) {
            res = (res - x * 2 % MOD + MOD) % MOD;
        }
        return res;
    }
};