#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> _pricing;
    vector<vector<int>> _grid;

    bool check(int i, int j) {
        int p = _grid[i][j];
        return p >= _pricing[0] && p <= _pricing[1];
    }

public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k) {
        using PII = pair<int, int>;
        _pricing = pricing, _grid = grid;
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<bool>> st(n, vector<bool>(m));
        vector<vector<int>> res;
        queue<PII> q;
        q.emplace(start[0], start[1]);
        st[start[0]][start[1]] = true;
        if (check(start[0], start[1])) res.push_back(start);
        while (!q.empty() && res.size() < k) {
            vector<vector<int>> tmp;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int a = t.first + dx[i], b = t.second + dy[i];
                    if (a < 0 || a == n || b < 0 || b == m || !grid[a][b] || st[a][b]) continue;
                    st[a][b] = true;
                    q.push({a, b});
                    if (check(a, b)) tmp.push_back({a, b});
                }
            }
            sort(tmp.begin(), tmp.end(), [&](const vector<int> &a, const vector<int> &b) {
                if (grid[a[0]][a[1]] != grid[b[0]][b[1]]) return grid[a[0]][a[1]] < grid[b[0]][b[1]];
                if (a[0] != b[0]) return a[0] < b[0];
                return a[1] < b[1];
            });
            for (auto &v: tmp) {
                if (grid[v[0]][v[1]] > 1) res.push_back(v);
            }
        }
        while (res.size() > k) res.pop_back();
        return res;
    }
};