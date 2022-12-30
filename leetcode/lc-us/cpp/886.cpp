#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool dfs(int i, int c, vector<vector<int>> &paths, vector<int> &color) {
        color[i] = c;
        for (int j: paths[i]) {
            if (!color[j]) {
                if (!dfs(j, 3 - c, paths, color)) {
                    return false;
                }
            } else if (color[j] == c) {
                return false;
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        vector<vector<int>> paths(n + 1);
        vector<int> color(n + 1);
        for (auto &d: dislikes) {
            paths[d[0]].push_back(d[1]);
            paths[d[1]].push_back(d[0]);
        }
        for (int i = 1; i <= n; i++) {
            if (!color[i]) {
                if (!dfs(i, 1, paths, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};