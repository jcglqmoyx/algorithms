#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        vector<int> res(n);
        unordered_map<int, vector<int>> map;
        for (const auto &path: paths) {
            map[path[0] - 1].push_back(path[1] - 1);
            map[path[1] - 1].push_back(path[0] - 1);
        }
        for (int i = 0; i < n; i++) {
            unordered_set<int> colors = {1, 2, 3, 4};
            for (int neighbor: map[i]) {
                colors.erase(res[neighbor]);
            }
            res[i] = (*colors.begin());
        }
        return res;
    }
};