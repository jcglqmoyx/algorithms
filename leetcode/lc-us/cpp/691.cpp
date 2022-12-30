#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int INF = 20;
    int n;
    vector<string> _stickers;
    string _target;
    int f[1 << 15], g[1 << 15][26];

    int fill(int state, char c) {
        int &v = g[state][c - 'a'];
        if (v != -1) return v;
        for (int i = 0; i < n; i++) {
            if (!(state >> i & 1) && _target[i] == c) {
                state |= 1 << i;
                break;
            }
        }
        return v = state;
    }

    int dfs(int state) {
        int &v = f[state];
        if (v != -1) return v;
        else if (state == (1 << n) - 1) return v = 0;
        v = INF;
        for (auto &s: _stickers) {
            int t = state;
            for (char c: s) {
                t = fill(t, c);
            }
            if (t != state) {
                v = min(v, dfs(t) + 1);
            }
        }
        return v;
    }

public:
    int minStickers(vector<string> &stickers, string target) {
        n = (int) target.size(), _stickers = stickers, _target = target;
        memset(f, -1, sizeof f), memset(g, -1, sizeof g);
        int res = dfs(0);
        if (res == INF) res = -1;
        return res;
    }
};