#include <bits/stdc++.h>

using namespace std;

class Solution {
    int cnt = 0;
    vector<int> p;
    vector<int> rk;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void connect(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rk[px] > rk[py]) swap(px, py);
        p[px] = py;
        rk[py] += rk[px];
        cnt--;
    }

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>> &positions) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        bool st[m][n];
        memset(st, false, sizeof st);
        int size = m * n;
        p.resize(size), rk.resize(size);
        for (int i = 0; i < size; i++) p[i] = i, rk[i] = 1;
        vector<int> res;
        for (auto &pos: positions) {
            int x = pos[0], y = pos[1];
            if (st[x][y]) {
                res.push_back(cnt);
                continue;
            }
            st[x][y] = true;
            cnt++;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a == m || b < 0 || b == n || !st[a][b]) continue;
                connect(x * n + y, a * n + b);
            }
            res.push_back(cnt);
        }
        return res;
    }
};