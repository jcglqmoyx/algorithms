#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9 + 7;
        int max_index = min(arrLen - 1, steps);
        vector<int> f(steps + 1);
        f[0] = 1;
        for (int i = 1; i <= steps; i++) {
            vector<int> t = f;
            for (int j = 0; j <= max_index; j++) {
                if (j) t[j] = (t[j] + f[j - 1]) % MOD;
                if (j + 1 <= max_index) t[j] = (t[j] + f[j + 1]) % MOD;
            }
            f = t;
        }
        return f[0];
    }
};