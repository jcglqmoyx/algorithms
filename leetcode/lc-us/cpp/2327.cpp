#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        int s[n + 1];
        memset(s, 0, sizeof s);
        s[1] = 1;
        for (int i = 2; i <= n; i++) {
            int f = (s[max(0, i - delay)] - s[max(0, i - forget)] + MOD) % MOD;
            s[i] = (s[i - 1] + f) % MOD;
        }
        return (s[n] - s[n - forget] + MOD) % MOD;;
    }
};