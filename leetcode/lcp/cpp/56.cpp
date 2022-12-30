#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int conveyorBelt(vector<string> &matrix, vector<int> &start, vector<int> &end) {
        using PII = pair<int, int>;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        unordered_map<char, int> M = {
                {'v', 0},
                {'>', 1},
                {'^', 2},
                {'<', 3},
        };
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        vector<vector<int>> f(n, vector<int>(m, n * m));
        f[start[0]][start[1]] = 0;
        queue<PII> q;
        q.push({start[0], start[1]});
        while (!q.empty()) {
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                int x = t.first, y = t.second;
                for (int i = 0; i < 4; i++) {
                    int a = x + dx[i], b = y + dy[i];
                    if (a < 0 || a == n || b < 0 || b == m) continue;
                    int d = M[matrix[x][y]];
                    if (d == i) {
                        if (f[x][y] < f[a][b]) {
                            f[a][b] = f[x][y];
                            q.push({a, b});
                        }
                    } else {
                        if (f[x][y] + 1 < f[a][b]) {
                            f[a][b] = f[x][y] + 1;
                            q.push({a, b});
                        }
                    }
                }
            }
        }
        return f[end[0]][end[1]];
    }
};