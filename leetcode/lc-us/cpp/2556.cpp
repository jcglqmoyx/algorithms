#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int num[N], low[N], idx;
bool vis[N], flag[N];

vector<vector<int>> g;

void tarjan(int u, int father) {
    vis[u] = true;
    low[u] = num[u] = ++idx;
    int children = 0;
    for (auto v: g[u]) {
        if (!vis[v]) {
            children++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (father != u && low[v] >= num[u] && !flag[u]) {
                flag[u] = true;
            }
        } else if (v != father) {
            low[u] = min(low[u], num[v]);
        }
    }
    if (father == u && children >= 2 && !flag[u]) {
        flag[u] = true;
    }
}

int get(int x, int y) {
    return x * m + y;
}

class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isPossibleToCutPath(vector<vector<int>> &grid) {
        idx = 0;
        n = (int) grid.size(), m = (int) grid[0].size();
        memset(vis, 0, sizeof vis);
        memset(flag, 0, sizeof flag);
        memset(num, 0, sizeof num);
        memset(low, 0, sizeof low);
        g.clear();
        g.resize(100001);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    int p = get(i, j);
                    for (int d = 0; d < 4; d++) {
                        int x = i + dx[d], y = j + dy[d];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y]) {
                            int u = get(x, y);
                            g[p].push_back(u);
                            g[u].push_back(p);
                        }
                    }
                }
            }
        }

        vector<bool> st(n * m);
        st[0] = false;
        queue<pair<int, int>> qq;
        qq.push({0, 0});
        while (!qq.empty()) {
            auto t = qq.front();
            qq.pop();
            int x = t.first, y = t.second;
            int p = get(x, y);
            for (int ne: g[p]) {
                if (!st[ne]) {
                    int a = ne / m, b = ne % m;
                    qq.push({a, b});
                    st[ne] = true;
                }
            }
        }
        if (!st[n * m - 1]) return true;

        for (int i = 0; i < n * m; i++) {
            if (!vis[i]) {
                idx = 0;
                tarjan(i, i);
            }
        }
        for (int i = 0; i < n * m; i++) {
            if (flag[i]) {
                return true;
            }
        }
        return false;
    }
};