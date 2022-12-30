#include <bits/stdc++.h>

using namespace std;

class Solution {
    using PII = pair<int, int>;

    int n, m;
    vector<vector<int>> g;
    vector<pair<int, int>> area;
    vector<vector<bool>> st;

    void dfs(int i, int j) {
        if (i < 0 || j < 0 || i == n || j == m || st[i][j] || !g[i][j]) {
            return;
        }
        area.emplace_back(i, j);
        st[i][j] = true;
        dfs(i, j + 1);
        dfs(i, j - 1);
        dfs(i + 1, j);
        dfs(i - 1, j);
    }

    vector<PII> get_coordinates(int x, int y) {
        return {{x,  y},
                {-x, y},
                {x,  -y},
                {-x, -y},
                {y,  x},
                {y,  -x},
                {-y, x},
                {-y, -x}};
    }

    string get_max_representation() {
        vector<vector<PII>> v(8);
        for (auto &point: area) {
            auto t = get_coordinates(point.first, point.second);
            for (int i = 0; i < 8; i++) {
                v[i].push_back(t[i]);
            }
        }
        for (auto &i: v) {
            sort(i.begin(), i.end());
            int x0 = i[0].first, y0 = i[0].second;
            for (auto &j: i) {
                j.first -= x0, j.second -= y0;
            }
        }
        vector<PII> mx;
        for (auto &i: v) {
            mx = max(mx, i);
        }
        string res;
        for (auto &p: mx) {
            res += to_string(p.first);
            res.push_back(' ');
            res += to_string(p.second);
            res.push_back(' ');
        }
        res.push_back('#');
        return res;
    }

public:
    int numDistinctIslands2(vector<vector<int>> &grid) {
        n = (int) grid.size(), m = (int) grid[0].size(), g = grid;
        st = vector<vector<bool>>(n, vector<bool>(m));
        unordered_set<string> S;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !st[i][j]) {
                    area.clear();
                    dfs(i, j);
                    S.insert(get_max_representation());
                }
            }
        }
        return (int) S.size();
    }
};