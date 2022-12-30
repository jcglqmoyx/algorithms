#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>> &edges, int source, int destination) {
        vector<int> deg(n);
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[1]].push_back(e[0]);
            deg[e[0]]++;
        }
        if (deg[destination]) return false;
        queue<int> q;
        q.push(destination);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            if (t == source) return true;
            for (int x: g[t]) {
                if (--deg[x] == 0) {
                    q.push(x);
                }
            }
        }
        return false;
    }
};