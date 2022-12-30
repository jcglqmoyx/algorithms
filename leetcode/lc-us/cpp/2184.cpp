#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int buildWall(int height, int width, vector<int> &bricks) {
        const int MOD = 1e9 + 7;
        sort(bricks.begin(), bricks.end());
        vector<vector<int>> first_row;
        vector<int> v;
        function<void(int)> dfs = [&](int left) {
            for (int w: bricks) {
                if (!left) {
                    first_row.push_back(v);
                }
                if (w <= left) {
                    v.push_back(w);
                    dfs(left - w);
                    v.pop_back();
                } else {
                    break;
                }
            }
        };

        dfs(width);

        int n = (int) first_row.size();
        if (!n) return 0;

        bool st[n][n];
        memset(st, false, sizeof st);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    if (first_row[i].size() == 1) st[i][j] = true;
                    continue;
                }
                int li = first_row[i][0], lj = first_row[j][0];
                bool flag = true;
                int p = 1, q = 1;
                while (li < width && lj < width) {
                    if (li < lj) li += first_row[i][p++];
                    else if (li > lj) lj += first_row[j][q++];
                    else {
                        flag = false;
                        break;
                    }
                }
                st[i][j] = flag;
            }
        }

        vector<int> f(n, 1);
        for (int i = 1; i < height; i++) {
            vector<int> g(n);
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (st[j][k]) {
                        g[k] = (f[j] + g[k]) % MOD;
                    }
                }
            }
            f = move(g);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + f[i]) % MOD;
        }
        return res;
    }
};