#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int extractMantra(vector<string> &g, string s) {
        int n = (int) g.size(), m = (int) g[0].size();
        bool st1[26]{}, st2[26]{};
        for (auto &r: g) {
            for (char c: r) {
                st1[c - 'a'] = true;
            }
        }
        for (char c: s) st2[c - 'a'] = true;
        for (int c = 0; c < 26; c++) {
            if (!st1[c] && st2[c]) return -1;
        }
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        int f[n][m][(int) s.size() + 1];
        memset(f, 0x3f, sizeof f);
        f[0][0][0] = 0;
        struct T {
            int x, y;
            int match;
        };
        queue<T> q;
        q.push({0, 0, 0});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.x, y = t.y, match = t.match;
            if (g[x][y] == s[match] && f[x][y][match + 1] > f[x][y][match] + 1) {
                f[x][y][match + 1] = f[x][y][match] + 1;
                q.push({x, y, match + 1});
            }
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a == n || b < 0 || b == m) continue;
                if (f[a][b][match] > f[x][y][match] + 1) {
                    f[a][b][match] = f[x][y][match] + 1;
                    q.push({a, b, match});
                }
            }
        }
        int res = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = min(res, f[i][j][(int) s.size()]);
            }
        }
        return res;
    }
};