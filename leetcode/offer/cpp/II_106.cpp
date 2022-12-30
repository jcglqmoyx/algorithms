#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        flag = true, g = graph;
        for (int i = 0; i < graph.size(); i++) {
            if (!g[i].empty()) {
                if (color.count(i)) {
                    if (color[i] == 'B') dfs(i, 'W');
                    else dfs(i, 'B');
                } else {
                    color[i] = 'B', dfs(i, 'W');
                }
            }
        }
        return flag;
    }

private:
    bool flag;
    unordered_map<int, char> color;
    vector<vector<int>> g;

    void dfs(int i, char c) {
        for (int j: g[i]) {
            if (color.count(j)) {
                if (color[j] != c) {
                    flag = false;
                    return;
                }
            } else {
                color[j] = c;
                if (c == 'W') dfs(j, 'B');
                else dfs(j, 'W');
            }
        }
    }
};