#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSpecialSubsequences(vector<int> &nums) {
        static constexpr int MOD = 1e9 + 7;

        long long f0 = 0, f1 = 0, f2 = 0;
        for (int x: nums) {
            if (x == 0) f0 = (f0 * 2 + 1) % MOD;
            else if (x == 1) f1 = (f0 + f1 * 2) % MOD;
            else if (x == 2) f2 = (f1 + f2 * 2) % MOD;
        }
        return (int) f2;
    }
};