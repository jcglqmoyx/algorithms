#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PLL = pair<LL, LL>;

const int N = 1e5 + 5;

int h[N], e[N], ne[N], idx;
int w[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
    PLL dfs(int u) {
        PLL res = {0, 0};
        LL f = 0;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            auto t = dfs(j);
            LL max_value = max(t.first, t.second);
            res.second += max_value;
            f = max(f, -max_value + t.second + w[j]);
        }
        res.first = res.second + f;
        return res;
    }

public:
    long long maxScore(vector<vector<int>> &edges) {
        memset(h, -1, sizeof h), idx = 0;
        for (int i = 0; i < edges.size(); i++) {
            int p = edges[i][0], v = edges[i][1];
            if (p != -1) add(p, i), w[i] = v;
        }
        auto t = dfs(0);
        return max(t.first, t.second);
    }
};