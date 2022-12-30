#include <bits/stdc++.h>

using namespace std;

class Solution {
    int size = 0;
    vector<int> pond_sizes;

    void dfs(vector<vector<int>> &land, int i, int j) {
        if (i < 0 || i >= land.size() || j < 0 || j >= land[i].size() || land[i][j] != 0) {
            return;
        }
        land[i][j] = 1;
        size++;
        dfs(land, i + 1, j);
        dfs(land, i - 1, j);
        dfs(land, i, j + 1);
        dfs(land, i, j - 1);
        dfs(land, i - 1, j - 1);
        dfs(land, i - 1, j + 1);
        dfs(land, i + 1, j - 1);
        dfs(land, i + 1, j + 1);
    }

public:
    vector<int> pondSizes(vector<vector<int>> &land) {
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[i].size(); j++) {
                if (land[i][j] == 0) {
                    dfs(land, i, j);
                    pond_sizes.push_back(size);
                    size = 0;
                }
            }
        }
        return pond_sizes;
    }
};