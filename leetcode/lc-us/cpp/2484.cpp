#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPalindromes(string s) {
        using LL = long long;
        const int MOD = 1e9 + 7;
        int n = (int) s.size();
        int pre[10][10]{}, suf[10][10]{}, pre_cnt[10]{}, suf_cnt[10]{};
        for (int i = n - 1; i >= 0; i--) {
            int d = s[i] - '0';
            for (int j = 0; j <= 9; j++) {
                suf[d][j] += suf_cnt[j];
            }
            suf_cnt[d]++;
        }
        LL res{}, cur{};
        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            suf_cnt[d]--;
            for (int j = 0; j <= 9; j++) {
                cur -= (LL) suf_cnt[j] * pre[j][d];
                suf[d][j] -= suf_cnt[j];
            }
            res += cur;
            for (int j = 0; j <= 9; j++) {
                cur += (LL) pre_cnt[j] * suf[d][j];
                pre[j][d] += pre_cnt[j];
            }
            pre_cnt[d]++;
        }
        return (int) (res % MOD);
    }
};