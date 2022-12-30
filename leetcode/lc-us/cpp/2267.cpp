#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>> &g) {
        int n = (int) g.size(), m = (int) g[0].size();
        if (g[0][0] == ')' || g[n - 1][m - 1] == '(') return false;

        int dx[] = {1, 0};
        int dy[] = {0, 1};

        bool st[n][m][n + m];
        memset(st, false, sizeof st);
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        while (!q.empty()) {
            auto[x, y, cnt] = q.front();
            q.pop();
            if (x == n - 1 && y == m - 1 && !cnt) return true;
            for (int i = 0; i < 2; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a == n || b == m) continue;
                int t = 1;
                if (g[a][b] == ')') t = -1;
                if (cnt + t < 0 || cnt + t > (n + m - 1) / 2) continue;
                if (st[a][b][cnt + t]) continue;
                q.push({a, b, cnt + t});
                st[a][b][cnt + t] = true;
            }
        }
        return false;
    }
};