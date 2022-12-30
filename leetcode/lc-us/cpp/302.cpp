#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minArea(vector<vector<char>> &image, int x, int y) {
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        int n = (int) image.size(), m = (int) image[0].size();
        bool st[n][m];
        memset(st, false, sizeof st);
        queue<pair<int, int>> q;
        q.emplace(x, y);
        int x1 = x, y1 = y, x2 = x, y2 = y;
        st[x][y] = true;
        while (!q.empty()) {
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int a = t.first + dx[i], b = t.second + dy[i];
                    if (a < 0 || a == n || b < 0 || b == m || st[a][b] || image[a][b] == '0') continue;
                    q.emplace(a, b);
                    st[a][b] = true;
                    x1 = min(x1, a), x2 = max(x2, a), y1 = min(y1, b), y2 = max(y2, b);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
};