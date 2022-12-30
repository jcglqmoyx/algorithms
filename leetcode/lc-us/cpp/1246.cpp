#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumMoves(vector<int> &arr) {
        int n = (int) arr.size();
        int f[n][n];
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > j) f[i][j] = 0;
                else if (i == j) f[i][j] = 1;
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (arr[i] == arr[j]) {
                    f[i][j] = f[i + 1][j - 1];
                    if (f[i][j] == 0) f[i][j]++;
                }
                for (int k = i; k < j; k++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                }
            }
        }
        return f[0][n - 1];
    }
};