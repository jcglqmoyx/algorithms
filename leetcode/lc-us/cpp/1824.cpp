#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSideJumps(vector<int> &obstacles) {
        typedef vector<int> VI;
        typedef vector<vector<int>> VVI;

        size_t n = obstacles.size();
        VVI f(n, VI(3, 0x3f3f3f3f));
        f[0][1] = 0;
        f[0][0] = f[0][2] = 1;
        for (int i = 1; i < n; i++) {
            if (obstacles[i] != 1) f[i][0] = f[i - 1][0];
            if (obstacles[i] != 2) f[i][1] = f[i - 1][1];
            if (obstacles[i] != 3) f[i][2] = f[i - 1][2];
            if (obstacles[i] != 1) f[i][0] = min(f[i][0], min(f[i][1], f[i][2]) + 1);
            if (obstacles[i] != 2) f[i][1] = min(f[i][1], min(f[i][0], f[i][2]) + 1);
            if (obstacles[i] != 3) f[i][2] = min(f[i][2], min(f[i][0], f[i][1]) + 1);
        }
        return min(f[n - 1][0], min(f[n - 1][1], f[n - 1][2]));
    }
};