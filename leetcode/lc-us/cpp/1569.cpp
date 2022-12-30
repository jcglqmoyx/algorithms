#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfWays(vector<int> &nums) {
        using LL = long long;
        const int MOD = 1e9 + 7;

        function<int(int, int)> qmi = [](int a, int b) -> int {
            int res = 1;
            while (b) {
                if (b & 1) res = (int) ((LL) res * a % MOD);
                a = (int) ((LL) a * a % MOD);
                b >>= 1;
            }
            return res;
        };

        int n = (int) nums.size();
        int f[n + 1], g[n + 1];
        f[0] = g[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = (int) ((LL) f[i - 1] * i % MOD);
            g[i] = (int) ((LL) g[i - 1] * qmi(i, MOD - 2) % MOD);
        }
        function<int(vector<int>)> dp = [&](vector<int> v) -> int {
            if (v.empty()) return 1;
            int n = (int) v.size();
            vector<int> l, r;
            int k = v[0];
            for (int i = 1; i < n; i++) {
                if (v[i] < k) l.push_back(v[i]);
                else r.push_back(v[i] - k);
            }
            return (int) (f[n - 1] * 1LL * g[k - 1] % MOD * g[n - k] % MOD * dp(l) % MOD * dp(r) % MOD);
        };
        return (dp(move(nums)) + MOD - 1) % MOD;
    }
};