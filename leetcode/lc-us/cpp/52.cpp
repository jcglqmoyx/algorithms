#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        _n = n;
        path = vector<string>(_n, string(_n, '.'));
        col = vector<bool>(_n, false);
        dg = vector<bool>(_n, false);
        udg = vector<bool>(_n, false);
        dfs(0);
        return cnt;
    }

private:
    int _n, cnt = 0;
    vector<bool> col, dg, udg;
    vector<string> path;

    void dfs(int u) {
        if (u == _n) {
            cnt++;
            return;
        }
        for (int i = 0; i < _n; i++) {
            if (!col[i] && !dg[i + u] && !udg[u + _n - i]) {
                col[i] = dg[i + u] = udg[u + _n - i] = true;
                path[u][i] = 'Q';
                dfs(u + 1);
                path[u][i] = '.';
                col[i] = dg[i + u] = udg[u + _n - i] = false;
            }
        }
    }
};
