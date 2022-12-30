#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPrintable(vector<vector<int>> &g) {
        int n = (int) g.size(), m = (int) g[0].size();
        int pos[61][4];
        for (int i = 1; i <= 60; i++) {
            pos[i][0] = n;
            pos[i][1] = m;
            pos[i][2] = -1;
            pos[i][3] = -1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = g[i][j];
                pos[x][0] = min(pos[x][0], i);
                pos[x][1] = min(pos[x][1], j);
                pos[x][2] = max(pos[x][2], i);
                pos[x][3] = max(pos[x][3], j);
            }
        }
        bool st[61] = {};
        while (true) {
            bool found = false;
            for (int i = 1; i <= 60; i++) {
                if (st[i] || pos[i][0] == n) continue;
                bool flag = true;
                for (int r = pos[i][0]; r <= pos[i][2]; r++) {
                    for (int c = pos[i][1]; c <= pos[i][3]; c++) {
                        if (g[r][c] != i && g[r][c] != -1) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (flag) {
                    found = true;
                    st[i] = true;
                    for (int r = pos[i][0]; r <= pos[i][2]; r++) {
                        for (int c = pos[i][1]; c <= pos[i][3]; c++) {
                            g[r][c] = -1;
                        }
                    }
                    break;
                }
            }
            if (!found) break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] != -1) {
                    return false;
                }
            }
        }
        return true;
    }
};