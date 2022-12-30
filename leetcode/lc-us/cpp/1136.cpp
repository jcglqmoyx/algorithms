#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>> &relations) {
        vector<int> degree(n + 1);
        vector<vector<int>> ne(n + 1);
        for (auto &r: relations) degree[r[1]]++, ne[r[0]].push_back(r[1]);
        queue<int> q;
        for (int i = 1; i <= n; i++) if (!degree[i]) q.push(i);
        int res = 0, processed = (int) q.size();
        if (q.empty()) return -1;
        while (!q.empty()) {
            for (size_t i = q.size(); i; i--) {
                auto t = q.front();
                q.pop();
                for (int neighbor: ne[t]) {
                    if (--degree[neighbor] == 0) {
                        q.push(neighbor);
                        processed++;
                    }
                }
            }
            res++;
        }
        if (processed != n) return -1;
        return res;
    }
};