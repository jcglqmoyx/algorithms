#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int specialPerm(vector<int> &nums) {
        int MOD = 1e9 + 7;
        int n = (int) nums.size();

        bool g[n][n];
        memset(g, 0, sizeof g);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = nums[i], y = nums[j];
                if (x % y == 0 || y % x == 0) {
                    g[i][j] = g[j][i] = true;
                }
            }
        }

        int f[n][1 << n];
        memset(f, -1, sizeof f);
        for (int i = 0; i < n; i++) f[i][1 << i] = 1;

        function<int(int, int)> dp = [&](int x, int y) -> int {
            int &v = f[x][y];
            if (v != -1) return v;
            v = 0;
            for (int i = 0; i < n; i++) {
                if (g[x][i] && y >> i & 1) {
                    v = (v + dp(i, y ^ (1 << x))) % MOD;
                }
            }
            return v;
        };

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + dp(i, (1 << n) - 1)) % MOD;
        }
        return res;
    }
};