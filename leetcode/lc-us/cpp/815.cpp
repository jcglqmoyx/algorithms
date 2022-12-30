#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
        if (source == target) return 0;
        int n = (int) routes.size();
        unordered_map<int, unordered_set<int>> g;
        vector<int> dist(n, 1e9);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            for (int x: routes[i]) {
                if (x == source) {
                    dist[i] = 1;
                    q.push(i);
                }
                g[x].insert(i);
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int x: routes[t]) {
                if (x == target) return dist[t];
                for (int p: g[x]) {
                    if (dist[p] > dist[t] + 1) {
                        dist[p] = dist[t] + 1;
                        q.push(p);
                    }
                }
                g.erase(x);
            }
        }
        return -1;
    }
};