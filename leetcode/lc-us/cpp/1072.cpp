#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        unordered_map<string, int> map;
        for (int i = 0; i < n; ++i) {
            string feature;
            for (int j = 0; j < m; ++j) {
                feature.push_back(matrix[i][j]);
            }
            if (feature[0] == 0) {
                for (int j = 0; j < m; ++j) {
                    feature[j] = 1 - feature[j];
                }
            }
            map[feature]++;
        }
        int ans = 0;
        for (const auto &p: map)
            ans = max(ans, p.second);
        return ans;
    }
};