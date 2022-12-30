#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
        vector<int> degree(n + 1);
        unordered_map<int, vector<int>> paths, reversed_paths;
        vector<int> mx(n + 1);
        for (auto &r: relations) {
            degree[r[1]]++;
            paths[r[0]].push_back(r[1]);
            reversed_paths[r[1]].push_back(r[0]);
        }
        int res = 0;
        queue<int> q;
        for (int i = 1; i < n + 1; i++) {
            if (degree[i] == 0) {
                q.push(i);
                mx[i] = time[i - 1];
                res = max(res, mx[i]);
            }
        }
        while (!q.empty()) {
            for (int idx = (int) q.size(); idx; idx--) {
                int t = q.front();
                q.pop();
                for (int prev: reversed_paths[t]) {
                    mx[t] = max(mx[t], mx[prev] + time[t - 1]);
                    res = max(res, mx[t]);
                }
                for (int ne: paths[t]) {
                    degree[ne]--;
                    if (degree[ne] == 0) {
                        q.push(ne);
                    }
                }
            }
        }
        return res;
    }
};