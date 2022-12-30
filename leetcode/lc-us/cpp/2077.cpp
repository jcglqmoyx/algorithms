#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>> &corridors) {
        vector<unordered_set<int>> g(n + 1);
        for (auto &c: corridors) {
            g[c[0]].insert(c[1]);
            g[c[1]].insert(c[0]);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j: g[i]) {
                if (j < i) continue;
                for (int k: g[j]) {
                    if (k < j) continue;
                    if (g[k].count(i)) cnt++;
                }
            }
        }
        return cnt;
    }
};