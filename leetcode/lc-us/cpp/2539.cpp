#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodSubsequences(string s) {
        using LL = long long;
        int MOD = 1e9 + 7;

        function<LL(LL, int)> quick_power = [&](LL a, int b) -> LL {
            LL res = 1;
            while (b) {
                if (b & 1) res = res * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return res;
        };

        unordered_map<char, int> cnt;
        for (char c: s) cnt[c]++;

        int n = (int) s.size(), res = 0;
        long f[n + 1], g[n + 1];
        f[0] = g[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] * i % MOD;
            g[i] = quick_power(f[i], MOD - 2);
        }

        for (int freq = 1; freq <= n; freq++) {
            LL t = 1;
            for (char a = 'a'; a <= 'z'; a++) {
                if (cnt[a] >= freq) {
                    t = t * ((f[cnt[a]] * g[freq] % MOD * g[cnt[a] - freq] + 1) % MOD) % MOD;
                }
            }
            if (t == 1) break;
            res = (int) ((res + t - 1 + MOD) % MOD);
        }
        return res;
    }
};