#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int INF = 1e9, N = 505;
    int n;
    int quietness;
    int ans;
    bool g[N][N];
    int cache[N];
    vector<int> res;

    void dfs(int idx, vector<int> &quiet) {
        for (int i = 0; i < n; i++) {
            if (g[idx][i]) {
                if (cache[i] != -1) {
                    if (cache[i] < quietness) {
                        quietness = cache[i];
                        ans = res[i];
                    }
                } else {
                    if (quiet[i] < quietness) {
                        quietness = quiet[i];
                        ans = i;
                    }
                    dfs(i, quiet);
                }
            }
        }
    }

public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
        n = (int) quiet.size();
        res.resize(n);
        memset(g, false, sizeof g), memset(cache, -1, sizeof cache);
        for (auto &r: richer) g[r[1]][r[0]] = true;
        for (int i = 0; i < n; i++) {
            quietness = INF;
            dfs(i, quiet);
            res[i] = quietness >= quiet[i] ? i : ans;
            cache[i] = min(quietness, quiet[i]);
        }
        return res;
    }
};