#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>> &grid) {
        using PII = pair<int, int>;
        const int INF = 0x3f3f3f3f;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INF));
        vector<vector<bool>> st(n, vector<bool>(m));
        deque<PII> q;
        dist[0][0] = 0;
        q.emplace_back(0, 0);
        while (!q.empty()) {
            auto t = q.front();
            q.pop_front();
            if (st[t.first][t.second]) continue;
            st[t.first][t.second] = true;
            for (int i = 0; i < 4; i++) {
                int x = t.first + dx[i], y = t.second + dy[i];
                if (x < 0 || x == n || y < 0 || y == m || st[x][y]) continue;
                int w = grid[t.first][t.second] - 1 != i;
                if (dist[x][y] > dist[t.first][t.second] + w) {
                    dist[x][y] = dist[t.first][t.second] + w;
                    if (w) q.emplace_back(x, y);
                    else q.push_front({x, y});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};