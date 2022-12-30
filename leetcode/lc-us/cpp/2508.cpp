#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>> &edges) {
        vector<unordered_set<int>> g(n + 1);
        vector<int> deg(n + 1);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            deg[x]++, deg[y]++;
            g[x].insert(y), g[y].insert(x);
        }
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (deg[i] & 1) v.push_back(i);
        }
        int m = (int) v.size();
        if (!m) return true;
        if (m > 4 || m & 1) return false;

        function<bool(int, int)> check = [&](int x, int y) -> bool {
            return !g[x].count(y);
        };

        if (m == 2) {
            int x = v[0], y = v[1];
            if (!g[x].count(y)) return true;

            for (int i = 1; i <= n; i++) {
                if (i == x || i == y) continue;
                if (!g[i].count(x) && !g[i].count(y)) return true;
            }
            return false;
        } else {
            int a = v[0], b = v[1], c = v[2], d = v[3];
            if (check(a, b) && check(c, d)) return true;
            if (check(a, c) && check(b, d)) return true;
            if (check(a, d) && check(b, c)) return true;
            return false;
        }
    }
};