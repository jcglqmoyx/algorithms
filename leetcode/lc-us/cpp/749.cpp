#include <bits/stdc++.h>

using namespace std;

class Solution {
    using QPII = queue<pair<int, int>>;
    static constexpr int N = 55;
    const int NORMAL = 0, INFECTED = 1, CONTROLLED = 2, TEMP = 3;

    int n, m;
    vector<vector<int>> _g;
    bool st[N][N];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool valid(int i, int j) const {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int get_area(int row, int col) {
        memset(st, false, sizeof st);
        _g[row][col] = TEMP;
        int area = 0;
        QPII q;
        q.push({row, col});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int a = t.first + dx[i], b = t.second + dy[i];
                if (valid(a, b)) {
                    if (_g[a][b] == NORMAL && !st[a][b]) {
                        st[a][b] = true;
                        area++;
                    } else if (_g[a][b] == INFECTED) {
                        _g[a][b] = TEMP;
                        q.push({a, b});
                    }
                }
            }
        }
        return area;
    }

    int get_cost(int row, int col) {
        memset(st, false, sizeof st);
        st[row][col] = true;
        QPII q;
        q.push({row, col});
        int cost = 0;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            _g[x][y] = CONTROLLED;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (valid(a, b)) {
                    if (_g[a][b] == NORMAL) cost++;
                    else if (_g[a][b] == INFECTED && !st[a][b]) {
                        q.push({a, b});
                        st[a][b] = true;
                    }
                }
            }
        }
        return cost;
    }

    int work() {
        int max_area = 0;
        int row, col;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (_g[i][j] == INFECTED) {
                    int area = get_area(i, j);
                    if (area > max_area) {
                        max_area = area;
                        row = i, col = j;
                    }
                }
            }
        }
        if (!max_area) return 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (_g[i][j] == TEMP) {
                    _g[i][j] = INFECTED;
                }
            }
        }
        int cost = get_cost(row, col);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (_g[i][j] == INFECTED) {
                    for (int idx = 0; idx < 4; idx++) {
                        int a = i + dx[idx], b = j + dy[idx];
                        if (valid(a, b) && _g[a][b] == NORMAL) {
                            _g[a][b] = 5;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (_g[i][j] == 5) {
                    _g[i][j] = INFECTED;
                }
            }
        }
        return cost;
    }

public:
    int containVirus(vector<vector<int>> &g) {
        n = (int) g.size(), m = (int) g[0].size(), _g = g;
        int res = 0;
        while (true) {
            int cost = work();
            if (!cost) break;
            res += cost;
        }
        return res;
    }
};