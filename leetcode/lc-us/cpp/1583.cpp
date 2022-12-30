#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs) {
        vector<vector<int>> g(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                g[i][preferences[i][j]] = j;
            }
        }
        unordered_map<int, int> pair_map;
        for (auto &p: pairs) pair_map[p[0]] = p[1], pair_map[p[1]] = p[0];
        int cnt = 0;
        for (int x = 0; x < n; x++) {
            for (int u = 0; u < n; u++) {
                if (g[x][u] < g[x][pair_map[x]] && g[u][x] < g[u][pair_map[u]]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};