#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        const int INF = 0x3f3f3f3f;
        int n = (int) ring.size(), m = (int) key.size();
        vector<int> f(n, INF);
        vector<vector<int>> pos(26);
        for (int i = 0; i < n; i++) pos[ring[i] - 'a'].push_back(i);
        for (int i: pos[key[0] - 'a']) {
            f[i] = min(i, n - i) + 1;
        }
        for (int i = 1; i < m; i++) {
            vector<int> g(n, INF);
            for (int j: pos[key[i - 1] - 'a']) {
                for (int k: pos[key[i] - 'a']) {
                    g[k] = min(g[k], f[j] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
            f = g;
        }
        int res = INF;
        for (int i = 0; i < n; i++) res = min(res, f[i]);
        return res;
    }
};