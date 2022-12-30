#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>> &queries) {
        init();
        int n = (int) queries.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int x = queries[i][0], y = queries[i][1];
            ll p = 1;
            for (int j = 0; j < prime_numbers.size() && prime_numbers[j] * prime_numbers[j] <= y; j++) {
                if (y % prime_numbers[j] == 0) {
                    int cnt = 0;
                    while (y % prime_numbers[j] == 0) {
                        cnt++;
                        y /= prime_numbers[j];
                    }
                    p = p * comb(x + cnt - 1, x - 1) % MOD;
                }
            }
            if (y != 1) p = p * x % MOD;
            res[i] = (int) p;

        }
        return res;
    }

private:
    using ll = long long;
    const static int N = 10010, MOD = 1e9 + 7;

    ll f[N], g[N];
    vector<int> prime_numbers;

    void init() {
        prime_numbers = get_prime_numbers();

        f[0] = g[0] = 1;
        for (int i = 1; i < N; i++) {
            f[i] = f[i - 1] * i % MOD;
            g[i] = modular_exponentiation(f[i], MOD - 2);
        }
    }

    ll modular_exponentiation(ll x, ll y) {
        ll res = 1;
        while (y) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }

    vector<int> get_prime_numbers() {
        vector<int> res;
        vector<bool> st(100);
        for (int i = 2; i < 100; i++) {
            if (!st[i]) res.push_back(i);
            for (int j = 0; res[j] * i < 100; j++) {
                st[res[j] * i] = true;
                if (i % res[j] == 0) break;
            }
        }
        return res;
    }

    ll comb(int a, int b) {
        return f[a] * g[b] % MOD * g[a - b] % MOD;
    }
};