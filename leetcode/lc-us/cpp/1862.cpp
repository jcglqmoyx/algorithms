#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfFlooredPairs(vector<int> &nums) {
        using LL = long long;
        const int MOD = 1e9 + 7;

        int mx = *max_element(nums.begin(), nums.end());
        vector<int> s(mx + 1);
        for (int num: nums) s[num]++;
        for (int i = 1; i <= mx; i++) s[i] += s[i - 1];
        int res = 0;
        for (int i = 1; i <= mx; i++) {
            for (int j = 1; j * i <= mx; j++) {
                int l = i * j, r = min(i * (j + 1) - 1, mx);
                int sum = (LL) j * (s[r] - s[l - 1]) % MOD;
                res = (res + (LL) (s[i] - s[i - 1]) * sum) % MOD;
            }
        }
        return res;
    }
};