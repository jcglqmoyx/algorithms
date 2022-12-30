#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change) {
        vector<vector<int>> f(n + 1, vector<int>(2, INT32_MAX)), g(n + 1, vector<int>());
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y), g[y].push_back(x);
        }
        f[1][0] = 0;
        queue<pair<int, int>> q;
        q.push({1, 0});
        while (f[n][1] == INT32_MAX) {
            for (auto it = q.size(); it; it--) {
                auto[pos, dist] = q.front();
                q.pop();
                for (int ne: g[pos]) {
                    if (dist + 1 < f[ne][0]) {
                        f[ne][0] = dist + 1;
                        q.push({ne, dist + 1});
                    } else if (dist + 1 > f[ne][0] && dist + 1 < f[ne][1]) {
                        f[ne][1] = dist + 1;
                        q.push({ne, dist + 1});
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < f[n][1]; i++) {
            if (res % (change << 1) >= change) {
                res += (change << 1) - res % (change << 1);
            }
            res += time;
        }
        return res;
    }
};