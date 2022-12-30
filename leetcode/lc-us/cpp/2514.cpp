#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MOD = 1e9 + 7;

class Solution {
    LL p[100010], g[100010];

    LL get(string &s) {
        int n = (int) s.size();
        LL res = p[n];
        int cnt[26] = {};
        for (char c: s) cnt[c - 'a']++;
        for (int i: cnt) {
            if (i) {
                res = res * g[i] % MOD;
            }
        }
        return res;
    }

    LL qmi(LL a, LL b) {
        LL res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    int countAnagrams(string s) {
        p[0] = g[0] = 1;
        for (int i = 1; i <= 100000; i++) {
            p[i] = p[i - 1] * i % MOD;
            g[i] = qmi(p[i], MOD - 2);
        }

        stringstream ss(s);
        string w;
        LL res = 1;
        while (ss >> w) {
            res = res * get(w) % MOD;
        }
        return (int) res;
    }
};