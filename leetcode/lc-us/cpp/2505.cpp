#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long subsequenceSumOr(vector<int> &nums) {
        using LL = long long;
        LL sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum == 0) return 0;
        int len = (int) log2(sum) + 2;
        int cnt[len];
        memset(cnt, 0, sizeof cnt);
        for (int x: nums) {
            for (int i = 0; i < len && x; i++) {
                if (x & 1) cnt[i]++;
                x >>= 1;
            }
        }
        LL res = 0;
        for (int i = 0, carry = 0; i < len; i++) {
            int t = cnt[i] + carry;
            carry = t >> 1;
            if (t) res |= 1LL << i;
        }
        return res;
    }
};