#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        vector<int> res(k);
        vector<pair<int, int>> map;
        for (int i = 0; i < mat.size(); i++) {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            map.emplace_back(sum, i);
        }
        sort(map.begin(), map.end());
        for (int i = 0; i < k; i++) {
            res[i] = map[i].second;
        }
        return res;
    }
};