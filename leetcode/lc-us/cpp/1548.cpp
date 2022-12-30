#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>> &roads, vector<string> &names, vector<string> &targetPath) {
        int m = (int) targetPath.size();
        vector<vector<int>> g(n);
        for (auto &r: roads) {
            int x = r[0], y = r[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int f[m + 1][n];
        memset(f, 0x3f, sizeof f);
        for (int j = 0; j < n; j++) f[0][j] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                int t = names[j] != targetPath[i - 1];
                for (int k: g[j]) {
                    f[i][j] = min(f[i][j], f[i - 1][k] + t);
                }
            }
        }
        int mn = 0x3f3f3f3f;
        for (int j = 0; j < n; j++) {
            mn = min(mn, f[m][j]);
        }
        int i = m, j;
        for (int k = 0; k < n; k++) {
            if (f[m][k] == mn) {
                j = k;
                break;
            }
        }
        vector<int> res = {j};
        while (i > 1) {
            for (int x: g[res.back()]) {
                int t = targetPath[i - 1] != names[res.back()];
                if (f[i - 1][x] + t == mn) {
                    res.push_back(x);
                    mn -= t;
                    i--;
                    break;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};