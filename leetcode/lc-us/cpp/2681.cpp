#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfPower(vector<int> &nums) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        long long res = 0, s = 0;
        for (long long x: nums) {
            res += x * x % MOD * (x + s);
            s = s * 2 + x;
            res %= MOD, s %= MOD;
        }
        return (int) res;
    }
};