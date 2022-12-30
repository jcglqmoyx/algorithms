#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
        int n = (int) patience.size();

        vector<vector<int>> paths(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            paths[x].push_back(y), paths[y].push_back(x);
        }
        vector<bool> st(n);
        st[0] = true;
        queue<int> q;
        q.push(0);
        int dist = 0;
        int res = 0;
        while (!q.empty()) {
            dist++;
            for (auto it = q.size(); it; it--) {
                int t = q.front();
                q.pop();
                for (int ne: paths[t]) {
                    if (st[ne]) continue;
                    q.push(ne);
                    int time = dist * 2;
                    res = max(res, time + (time - 1) / patience[ne] * patience[ne]);
                    st[ne] = true;
                }
            }
        }
        return res + 1;
    }
};