#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j] = f[i - 1][j] + f[i - 1][j - 1] + 1;
                if (f[i][j] >= n) return i;
            }
        }
        return -1;
    }
};