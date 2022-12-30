#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats) {
        using LL = long long;
        int n = (int) roads.size() + 1;
        int h[n], e[n << 1], ne[n << 1], idx = 0;
        memset(h, -1, sizeof h);
        function<void(int, int)> add = [&](int a, int b) {
            e[idx] = b, ne[idx] = h[a], h[a] = idx++;
        };
        for (auto &r: roads) {
            add(r[0], r[1]);
            add(r[1], r[0]);
        }
        LL res = 0;
        function<int(int, int)> dfs = [&](int u, int p) -> int {
            int people = 0;
            for (int i = h[u]; i != -1; i = ne[i]) {
                if (e[i] == p) continue;
                int t = dfs(e[i], u);
                people += t;
                res += (t + seats - 1) / seats;
            }
            return people + 1;
        };
        dfs(0, -1);
        return res;
    }
};