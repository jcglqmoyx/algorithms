#include <bits/stdc++.h>

using namespace std;

class Solution {
    int _k;

    vector<int> top_sort(vector<vector<int>> &v) {
        vector<int> deg(_k + 1);
        unordered_map<int, vector<int>> g;
        for (auto &p: v) {
            deg[p[1]]++;
            g[p[0]].push_back(p[1]);
        }
        queue<int> q;
        for (int i = 0; i <= _k; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for (int ne: g[t]) {
                if (--deg[ne] == 0) {
                    q.push(ne);
                }
            }
        }
        for (int i = 1; i <= _k; i++) {
            if (deg[i]) return {};
        }
        return res;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions) {
        _k = k;
        vector<int> row = top_sort(rowConditions);
        if (row.empty()) return {};
        vector<int> col = top_sort(colConditions);
        if (col.empty()) return {};
        row = vector<int>(row.begin() + 1, row.end());
        col = vector<int>(col.begin() + 1, col.end());

        unordered_map<int, int> row_map, col_map;
        for (int i = 0; i < k; i++) {
            row_map[row[i]] = i;
            col_map[col[i]] = i;
        }

        vector<vector<int>> res(k, vector<int>(k));
        for (int i = 1; i <= k; i++) {
            res[row_map[i]][col_map[i]] = i;
        }
        return res;
    }
};