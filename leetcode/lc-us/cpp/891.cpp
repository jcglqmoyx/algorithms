#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int> &nums) {
        using ll = long long;
        const int MOD = 1e9 + 7;
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        ll res = 0;
        vector<ll> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow2[i] = pow2[i - 1] * 2 % MOD;
        }
        for (int i = 0; i < n; i++) {
            res = (res + nums[i] * (pow2[i])) % MOD;
            res = (res - nums[i] * pow2[n - i - 1]) % MOD;
        }
        return (int) res;
    }
};