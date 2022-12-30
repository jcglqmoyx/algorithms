#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>> &grid) {
        int n = (int) grid[0].size();
        if (n == 1) return 0;
        grid[0][0] = 0;
        grid[1][n - 1] = 0;
        vector<long long> pre(n), suf(n);
        pre[0] = grid[1][0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + grid[1][i];
        }
        suf[n - 1] = grid[0][n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + grid[0][i];
        }
        vector<long long> fi(n);
        fi[0] = suf[0];
        fi[n - 1] = pre[n - 1];
        for (int i = 1; i < n - 1; i++) {
            fi[i] = max(pre[i - 1], suf[i + 1]);
        }
        return *min_element(fi.begin(), fi.end());
    }
};