#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;
        int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        bool st[605][605];
        st[300][300] = true;
        memset(st, false, sizeof st);
        int step = 0;
        while (!q.empty()) {
            step++;
            for (auto it = q.size(); it; it--) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 8; i++) {
                    int a = t.first + dx[i], b = t.second + dy[i];
                    if (st[a + 300][b + 300]) continue;
                    st[a + 300][b + 300] = true;
                    q.push({a, b});
                    if (a == x && b == y) return step;
                }
            }
        }
        return step;
    }
};