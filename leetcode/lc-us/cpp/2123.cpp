#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>> &grid) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        int n = (int) grid.size(), m = (int) grid[0].size(), tot = n * m;
        vector<int> match(tot, -1);
        bool st[tot];
        vector<vector<int>> g(tot);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0 && grid[i][j]) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k], y = j + dy[k];
                        if (x < 0 || x == n || y < 0 || y == m || !grid[x][y]) continue;
                        g[i * m + j].push_back(x * m + y);
                    }
                }
            }
        }
        function<bool(int)> find = [&](int u) -> bool {
            for (int x: g[u]) {
                if (!st[x]) {
                    st[x] = true;
                    if (match[x] == -1 || find(match[x])) {
                        match[x] = u;
                        return true;
                    }
                }
            }
            return false;
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 0 && grid[i][j]) {
                    memset(st, false, sizeof st);
                    if (find(i * m + j)) res++;
                }
            }
        }
        return res;
    }
};