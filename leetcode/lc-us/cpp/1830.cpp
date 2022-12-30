#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int makeStringSorted(string s) {
        int cnt[26] = {};
        for (char c: s) {
            cnt[c - 'a']++;
        }
        int n = (int) s.size();
        int f[n + 1], g[n + 1];
        f[0] = g[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = (LL) f[i - 1] * i % MOD;
            g[i] = qmi(f[i], MOD - 2);
        }

        function<int()> calc = [&]() -> int {
            int sum = 0;
            for (int i: cnt) {
                sum += i;
            }
            int res = f[sum];
            for (int i: cnt) {
                if (i) {
                    res = (LL) res * g[i] % MOD;
                }
            }
            return res;
        };

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < s[i] - 'a'; j++) {
                if (cnt[j]) {
                    cnt[j]--;
                    res = (res + calc()) % MOD;
                    cnt[j]++;
                }
            }
            cnt[s[i] - 'a']--;
        }
        return res;
    }

private:
    using LL = long long;
    const int MOD = 1e9 + 7;

    int qmi(int x, int y) {
        int res = 1;
        while (y) {
            if (y & 1) res = (LL) res * x % MOD;
            x = (LL) x * x % MOD;
            y >>= 1;
        }
        return res;
    }
};