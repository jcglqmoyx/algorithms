#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                map[i - j].push_back(mat[i][j]);
            }
        }
        for (auto &x: map) {
            sort(x.second.begin(), x.second.end(), greater<>());
        }
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                mat[i][j] = map[i - j].back();
                map[i - j].pop_back();
            }
        }
        return mat;
    }
};