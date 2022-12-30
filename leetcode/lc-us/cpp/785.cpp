#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool dfs(int i, int c, vector<int> &color, unordered_map<int, vector<int>> &paths) {
        color[i] = c;
        for (int j: paths[i]) {
            if (!color[j]) {
                if (!dfs(j, 3 - c, color, paths)) {
                    return false;
                }
            } else if (color[j] == c) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = (int) graph.size();
        vector<int> color(n);
        unordered_map<int, vector<int>> paths;
        for (int i = 0; i < n; i++) {
            for (int j: graph[i]) {
                paths[i].push_back(j);
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (!color[i]) {
                if (!dfs(i, 1, color, paths)) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};