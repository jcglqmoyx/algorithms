#include <bits/stdc++.h>

using namespace std;

class Solution {
    int res, _n, _m;
    bool st[13][13];

    bool check(int x, int y, int len) {
        for (int i = x; i < x + len; i++) {
            for (int j = y + len - 1; j >= y; j--) {
                if (st[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    void fill(int x, int y, int len, bool b) {
        for (int i = x; i < x + len; i++) {
            for (int j = y; j < y + len; j++) {
                st[i][j] = b;
            }
        }
    }

    void dfs(int x, int y, int cnt) {
        if (cnt >= res) return;
        if (y == _m) x++, y = 0;
        if (x == _n) {
            res = min(res, cnt);
            return;
        }
        if (st[x][y]) {
            dfs(x, y + 1, cnt);
        } else {
            for (int len = min(_n - x, _m - y); len; len--) {
                if (check(x, y, len)) {
                    fill(x, y, len, true);
                    dfs(x, y + len, cnt + 1);
                    fill(x, y, len, false);
                }
            }
        }
    }

public:
    int tilingRectangle(int n, int m) {
        res = n * m;
        _n = n, _m = m;
        memset(st, false, sizeof st);
        dfs(0, 0, 0);
        return res;
    }
};