#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(string leaves) {
        int n = (int) leaves.size();
        int f[n][3];
        memset(f, 0x3f, sizeof f);
        f[0][0] = (leaves[0] != 'r');
        for (int i = 1; i < n; i++) {
            f[i][0] = (leaves[i] != 'r') + f[i - 1][0];
            f[i][1] = (leaves[i] != 'y') + min(f[i - 1][0], f[i - 1][1]);
            if (i >= 2) f[i][2] = (leaves[i] != 'r') + min(f[i - 1][1], f[i - 1][2]);
        }
        return f[n - 1][2];
    }
};