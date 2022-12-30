#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes) {
        for (int i = 0; i < n; i++) {
            pipes.push_back({0, i + 1, wells[i]});
        }
        sort(pipes.begin(), pipes.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
        vector<int> p(n + 2), sz(n + 2, 1);
        for (int i = 0; i < n + 2; i++) p[i] = i;
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        int res = 0;
        for (auto &pipe: pipes) {
            int x = pipe[0], y = pipe[1], cost = pipe[2];
            int px = find(x), py = find(y);
            if (px == py) continue;
            if (sz[px] > sz[py]) swap(px, py);
            p[px] = py;
            sz[py] += sz[px];
            res += cost;
        }
        return res;
    }
};