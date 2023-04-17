#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int h[N], e[N << 1], ne[N << 1], idx;
int cnt[N];
int f[N][2];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int s, int t, int p) {
    if (s == t) {
        cnt[s]++;
        return true;
    }
    for (int i = h[s]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != p) {
            if (dfs(j, t, s)) {
                cnt[s]++;
                return true;
            }
        }
    }
    return false;
}

int dp(vector<int> &price, int u, bool del, int p) {
    if (f[u][del] != -1) return f[u][del];
    int res = price[u] * cnt[u];
    if (del) res /= 2;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != p) {
            if (del) res += dp(price, j, false, u);
            else res += min(dp(price, j, false, u), dp(price, j, true, u));
        }
    }
    f[u][del] = res;
    return res;
}

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips) {
        memset(h, -1, sizeof h), idx = 0;
        memset(cnt, 0, sizeof cnt);
        memset(f, -1, sizeof f);
        for (auto &edge: edges) {
            add(edge[0], edge[1]);
            add(edge[1], edge[0]);
        }
        for (auto t: trips) {
            dfs(t[0], t[1], -1);
        }
        return min(dp(price, 0, false, -1), dp(price, 0, true, -1));
    }
};