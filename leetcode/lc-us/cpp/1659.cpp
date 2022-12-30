#include <bits/stdc++.h>

using namespace std;

int f[7][7][6][6][244];

class Solution {
public:
    int getMaxGridHappiness(int n, int m, int in, int out) {
        memset(f, 0, sizeof f);
        _n = n, _m = m;
        cases = (int) pow(3, m);
        return dp(in, out, 0, 0, 0);
    }

private:
    int _n, _m, cases;

    int dp(int ins, int outs, int i, int j, int st) {
        if (j == _m) i++, j = 0;
        if (i == _n) return 0;
        if (f[ins][outs][i][j][st]) return f[ins][outs][i][j][st];
        int ans = dp(ins, outs, i, j + 1, st * 3 % cases);
        bool left = false, up = false;
        int sub = 0, add = 0;
        if (j) {
            int x = st % 3;
            if (x == 1) sub += 30, left = true;
            else if (x == 2) add += 20, left = true;
        }
        if (i) {
            int x = st / (cases / 3);
            if (x == 1) sub += 30, up = true;
            else if (x == 2) add += 20, up = true;
        }
        if (ins) {
            int t = sub;
            if (up) t += 30;
            if (left) t += 30;
            ans = max(ans, dp(ins - 1, outs, i, j + 1, (st * 3 + 1) % cases) + 120 + add - t);
        }
        if (outs) {
            int t = add;
            if (up) t += 20;
            if (left) t += 20;
            ans = max(ans, dp(ins, outs - 1, i, j + 1, (st * 3 + 2) % cases) + 40 + t - sub);
        }
        return f[ins][outs][i][j][st] = ans;
    };
};