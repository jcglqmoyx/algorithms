#include <bits/stdc++.h>

using namespace std;

class Solution {
    int m, n;
    vector<int> f;

    int dp(int x) {
        if (f[x] != -1) return f[x];
        int sum = 0;
        for (int i = 0; i < m; i++) {
            if (x >> i & 1) {
                sum += i + 1;
            }
        }
        for (int i = 0; i < m; i++) {
            if (x >> i & 1) continue;
            if (sum + i + 1 >= n) return f[x] = 1;
            if (!dp(x + (1 << i))) return f[x] = 1;
        }
        return f[x] = 0;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        m = maxChoosableInteger, n = desiredTotal;
        if (m * (m + 1) / 2 < n) return false;
        f.resize(1 << m, -1);
        return dp(0);
    }
};