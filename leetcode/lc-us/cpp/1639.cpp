#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(vector<string> &words, string target) {
        const int MOD = 1e9 + 7;
        int n = (int) words[0].size(), m = (int) target.size();
        int cnt[n + 1][26];
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++) {
            for (auto &w: words) {
                cnt[i][w[i - 1] - 'a']++;
            }
        }
        long long f[n + 1][m + 1];
        memset(f, 0, sizeof f);
        for (int i = 0; i <= n; i++) f[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int idx = target[j - 1] - 'a';
                f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * cnt[i][idx]) % MOD;
            }
        }
        return (int) f[n][m];
    }
};