#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> paths;
    vector<int> path = {0};

    void dfs(vector<vector<int>> &graph, int index) {
        for (int i = 0; i < graph[index].size(); i++) {
            path.push_back(graph[index][i]);
            if (graph[index][i] == graph.size() - 1) {
                paths.push_back(path);
            }
            dfs(graph, graph[index][i]);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        dfs(graph, 0);
        return paths;
    }
};