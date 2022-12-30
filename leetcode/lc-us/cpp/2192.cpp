#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<unordered_set<int>> anc(n);
        vector<int> deg(n);
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            deg[y]++;
            g[x].push_back(y);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!deg[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int ne: g[t]) {
                anc[ne].insert(t);
                for (int ancestor: anc[t]) {
                    anc[ne].insert(ancestor);
                }
                if (!--deg[ne]) {
                    q.push(ne);
                }
            }
        }

        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            for (int x: anc[i]) res[i].push_back(x);
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};