#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>> &edges) {
        int n = (int) colors.size();
        vector<int> d(n);
        vector<vector<int>> paths(n), f(n, vector<int>(26));
        for (auto &e: edges) {
            paths[e[0]].push_back(e[1]);
            d[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (d[i] == 0) {
                q.push(i);
            }
        }
        vector<int> sorted;
        sorted.reserve(n);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            if (d[t] == 0) sorted.push_back(t);
            for (int j: paths[t]) {
                if (--d[j] == 0) {
                    q.push(j);
                }
            }
        }
        if (sorted.size() < n) return -1;
        int res = 1;
        for (int i: sorted) {
            int c = colors[i] - 'a';
            f[i][c] = max(f[i][c], 1);
            for (int j: paths[i]) {
                for (int k = 0; k < 26; k++) {
                    int t = 0;
                    if (colors[j] - 'a' == k) {
                        t = 1;
                    }
                    f[j][k] = max(f[j][k], f[i][k] + t);
                    res = max(res, f[j][k]);
                }
            }
        }
        return res;
    }
};