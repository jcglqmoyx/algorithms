#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int confusingNumberII(int n) {
        int res = 0;
        int f[5][2] = {{0, 0},
                       {1, 1},
                       {6, 9},
                       {8, 8},
                       {9, 6}};

        function<void(int, long long, int)> dfs = [&](int cur, long long reversed, int digit) {
            if (cur > n) return;
            if (cur != reversed) res++;
            if (cur > n / 10) return;
            for (int i = 0; i < 5; i++) {
                if (!i && !digit) continue;
                dfs(cur * 10 + f[i][0], reversed + (long long) pow(10, digit) * f[i][1], digit + 1);
            }
        };
        dfs(0, 0LL, 0);
        return res;
    }
};