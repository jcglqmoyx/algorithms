#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, m;
    bool st[200];
    vector<int> match;

    bool find(vector<vector<int>> &g, int x) {
        for (int j = 0; j < m; j++) {
            if (g[x][j] && !st[j]) {
                st[j] = true;
                if (match[j] == -1 || find(g, match[j])) {
                    match[j] = x;
                    return true;
                }
            }
        }
        return false;
    }

public:
    int maximumInvitations(vector<vector<int>> &grid) {
        int res = 0;
        n = (int) grid.size(), m = (int) grid[0].size();
        match.resize(m, -1);
        for (int i = 0; i < n; i++) {
            memset(st, false, sizeof st);
            if (find(grid, i)) {
                res++;
            }
        }
        return res;
    }
};