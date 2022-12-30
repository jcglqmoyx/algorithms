#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = (int) graph.size();
        vector<int> d(n);
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            for (int j: graph[i]) {
                d[i]++;
                g[j].push_back(i);
            }
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (d[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int next: g[t]) {
                if (--d[next] == 0) {
                    q.push(next);
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (d[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};