#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int INF = 1e9;
    typedef pair<int, int> PII;
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = (int) graph.size();
        vector<vector<int>> f(1 << n, vector<int>(n, INF));
        queue<PII> q;
        for (int i = 0; i < n; i++) {
            int state = 1 << i, start = i;
            f[state][start] = 0;
            q.push({state, start});
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int state = t.first, start = t.second;
            for (int ne: graph[start]) {
                int a = state | 1 << ne, b = ne;
                if (f[a][b] > f[state][start] + 1) {
                    f[a][b] = f[state][start] + 1;
                    q.push({a, b});
                }
            }
        }
        int res = INF;
        for (int i = 0; i < n; i++) res = min(res, f[(1 << n) - 1][i]);
        return res;
    }
};