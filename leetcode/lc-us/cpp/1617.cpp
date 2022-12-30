#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges) {
        const int INF = 100;
        const int N = 1 << n;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        vector<int> f(N);
        for (auto &e: edges) {
            int x = e[0] - 1, y = e[1] - 1;
            dist[x][y] = dist[y][x] = 1;
            f[1 << x | 1 << y] = 1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for (int state = 1; state < N; state++) {
            if (!f[state]) continue;
            for (int i = 0; i < n; i++) {
                int new_state = state | 1 << i;
                if (state >> i & 1 || f[new_state]) continue;
                for (int j = 0; j < n; j++) {
                    if (j == i || dist[j][i] != 1 || !(state >> j & 1)) continue;
                    f[new_state] = f[state];
                    for (int k = 0; k < n; k++) {
                        if (!(state >> k & 1)) continue;
                        f[new_state] = max(f[new_state], dist[i][k]);
                    }
                    break;
                }
            }
        }
        vector<int> res(n - 1);
        for (int i = 1; i < N; i++) {
            if (f[i]) res[f[i] - 1]++;
        }
        return res;
    }
};