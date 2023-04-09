#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>> &g) {
        const int INF = 0x3f3f3f3f;
        int n = (int) g.size(), m = (int) g[0].size();
        if (n == 1 && m == 1) return 1;

        set<int> row[n], col[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i].insert(j);
                col[j].insert(i);
            }
        }

        int f[n][m];
        memset(f, 0x3f, sizeof f);
        f[0][0] = 1;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        while (!q.empty()) {
            for (auto ite = q.size(); ite; ite--) {
                auto t = q.front();
                q.pop();
                int x = t.first, y = t.second;
                int right = min(m - 1, g[x][y] + y);
                auto it = row[x].upper_bound(y);
                while (it != row[x].end() && *it <= right) {
                    if (f[x][*it] > f[x][y] + 1) {
                        f[x][*it] = f[x][y] + 1;
                        q.emplace(x, *it);
                        col[*it].erase(x);
                        it = row[x].erase(it);
                    } else {
                        it++;
                    }
                }

                int down = min(n - 1, g[x][y] + x);
                it = col[y].upper_bound(x);
                while (it != col[y].end() && *it <= down) {
                    if (f[*it][y] > f[x][y] + 1) {
                        f[*it][y] = f[x][y] + 1;
                        q.emplace(*it, y);
                        row[*it].erase(y);
                        it = col[y].erase(it);
                    } else {
                        it++;
                    }
                }
            }
        }
        return f[n - 1][m - 1] == INF ? -1 : f[n - 1][m - 1];
    }
};