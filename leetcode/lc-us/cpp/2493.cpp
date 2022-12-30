#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n + 1);
        int res = 0;
        bool flag = true;

        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) p[i] = i;

        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };

        for (auto &e: edges) {
            int x = e[0], y = e[1];
            p[find(x)] = find(y);
        }
        unordered_map<int, vector<int>> map;
        for (int i = 1; i <= n; i++) {
            int pi = find(i);
            map[pi].push_back(i);
        }

        int m;
        function<void(int)> bfs = [&](int u) {
            queue<int> q;
            int id[n + 1];
            memset(id, -1, sizeof id);
            q.push(u);
            while (!q.empty()) {
                m++;
                for (auto it = q.size(); it; it--) {
                    auto t = q.front();
                    q.pop();
                    id[t] = m;
                    for (int x: g[t]) {
                        if (id[x] != -1) {
                            if (abs(m - id[x]) != 1) {
                                flag = false;
                                return;
                            }
                        } else {
                            id[x] = m + 1;
                            q.push(x);
                        }
                    }
                }
            }
        };

        for (auto &[k, v]: map) {
            int mx = 0;
            for (int x: v) {
                m = 0;
                bfs(x);
                mx = max(mx, m);
            }
            if (!flag) return -1;
            res += mx;
        }
        return res;
    }
};