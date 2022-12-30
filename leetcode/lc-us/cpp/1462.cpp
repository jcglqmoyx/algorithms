#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
        vector<vector<bool>> d(n, vector<bool>(n));
        for (auto &p: prerequisites) d[p[0]][p[1]] = true;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (d[i][k] && d[k][j]) d[i][j] = true;
                }
            }
        }
        vector<bool> res;
        res.reserve(queries.size());
        for (auto &q: queries) {
            res.push_back(d[q[0]][q[1]]);
        }
        return res;
    }
};