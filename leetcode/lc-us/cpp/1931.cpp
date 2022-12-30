#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;

        int total_mask = (int) pow(3, m);
        unordered_map<int, vector<int>> map;
        for (int mask = 0; mask < total_mask; mask++) {
            vector<int> color;
            int t = mask;
            for (int i = 0; i < m; i++) {
                color.push_back(t % 3);
                t /= 3;
            }
            bool valid = true;
            for (int i = 0; i < m - 1; i++) {
                if (color[i] == color[i + 1]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                map[mask] = move(color);
            }
        }

        unordered_map<int, vector<int>> ne;
        for (auto[i, _]: map) {
            for (auto[j, _]: map) {
                bool valid = true;
                for (int k = 0; k < m; k++) {
                    if (map[i][k] == map[j][k]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    ne[i].push_back(j);
                }
            }
        }


        int f[total_mask];
        for (auto[mask, _]: map) {
            f[mask] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            int g[total_mask];
            memset(g, 0, sizeof g);
            for (auto[j, _]: map) {
                for (int k: ne[j]) {
                    g[j] = (g[j] + f[k]) % MOD;
                }
            }
            for (int j = 0; j < total_mask; j++) {
                f[j] = g[j];
            }
        }
        int res = 0;
        for (auto[mask, _]: map) {
            res = (res + f[mask]) % MOD;
        }
        return res;
    }
};