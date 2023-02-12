#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
        const int INF = 0x3f3f3f3f;
        const int RED = 0, BLUE = 1;
        vector<vector<int>> rg(n), bg(n);
        for (auto &e: redEdges) rg[e[0]].push_back(e[1]);
        for (auto &e: blueEdges) bg[e[0]].push_back(e[1]);
        int dist[n][2];
        memset(dist, 0x3f, sizeof dist);
        dist[0][0] = dist[0][1] = 0;
        queue<tuple<int, int, int>> q;
        q.push({0, RED, 0});
        q.push({0, BLUE, 0});
        while (!q.empty()) {
            auto[p, c, d] = q.front();
            q.pop();
            if (c == RED) {
                for (int ne: bg[p]) {
                    if (dist[ne][BLUE] > d + 1) {
                        dist[ne][BLUE] = d + 1;
                        q.push({ne, BLUE, d + 1});
                    }
                }
            } else {
                for (int ne: rg[p]) {
                    if (dist[ne][RED] > d + 1) {
                        dist[ne][RED] = d + 1;
                        q.push({ne, RED, d + 1});
                    }
                }
            }
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int t = min(dist[i][0], dist[i][1]);
            if (t == INF) res[i] = -1;
            else res[i] = t;
        }
        return res;
    }
};