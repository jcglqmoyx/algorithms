#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
        int n = (int) coins.size();
        bool deleted[n];
        memset(deleted, 0, sizeof deleted);
        int d[n];
        memset(d, 0, sizeof d);
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y), g[y].push_back(x);
            d[x]++, d[y]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!coins[i] && d[i] == 1) q.push(i);
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            deleted[t] = true;
            for (int x: g[t]) {
                if (--d[x] == 1 && !coins[x]) {
                    q.push(x);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (d[i] == 1 && coins[i]) {
                deleted[i] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            if (deleted[i] && coins[i]) {
                for (int x: g[i]) d[x]--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (d[i] == 1) deleted[i] = true;
        }
        int res = 0;
        for (auto &e: edges) {
            if (!deleted[e[0]] && !deleted[e[1]]) res += 2;
        }
        return res;
    }
};