#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWeight(vector<vector<int>> &edges, vector<int> &value) {
        int N = (int) value.size(), M = (int) edges.size(), count[N];

        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b) {
            return value[a[0]] + value[a[1]] > value[b[0]] + value[b[1]];
        });

        memset(count, 0, sizeof(count));
        for (auto v: edges) {
            count[v[0]]++;
            count[v[1]]++;
        }

        vector<pair<int, int>> G[N];
        for (int i = 0; i < M; i++) {
            if (count[edges[i][0]] < count[edges[i][1]] ||
                (count[edges[i][0]] == count[edges[i][1]] && edges[i][0] < edges[i][1])) {
                G[edges[i][0]].emplace_back(edges[i][1], i);
            } else {
                G[edges[i][1]].emplace_back(edges[i][0], i);
            }
        }

        vector<int> nodes[M];
        int vis[N], id[N];
        memset(vis, 0xff, sizeof vis);
        for (int i = 0; i < M; i++) {
            for (pair<int, int> &ne: G[edges[i][0]]) {
                vis[ne.first] = i, id[ne.first] = ne.second;
            }
            for (pair<int, int> &ne: G[edges[i][1]]) {
                if (vis[ne.first] == i) {
                    nodes[ne.second].push_back(edges[i][0]);
                    nodes[id[ne.first]].push_back(edges[i][1]);
                    nodes[i].push_back(ne.first);
                }
            }
        }

        vector<int> C[N];
        for (int i = 0; i < M; i++) {
            for (int n: nodes[i]) {
                C[n].push_back(i);
            }
        }

        int res = 0;
        for (int i = 0; i < N; i++) {
            int bound = (int) C[i].size() - 1;
            for (int a = 0; a < min(3, (int) C[i].size()) && bound >= a; a++) {
                for (int b = a; b <= bound; ++b) {
                    int cur = value[i] + value[edges[C[i][a]][0]] + value[edges[C[i][a]][1]], cnt = 0;
                    if (edges[C[i][b]][0] != edges[C[i][a]][0] && edges[C[i][b]][0] != edges[C[i][a]][1]) {
                        cur += value[edges[C[i][b]][0]], cnt++;
                    }
                    if (edges[C[i][b]][1] != edges[C[i][a]][0] && edges[C[i][b]][1] != edges[C[i][a]][1]) {
                        cur += value[edges[C[i][b]][1]], cnt++;
                    }
                    res = max(res, cur);
                    if (cnt == 2) {
                        bound = b - 1;
                        break;
                    }
                }
            }
        }
        return res;
    }
};