#include <bits/stdc++.h>

using namespace std;

class Solution {
    int goal;
    vector<int> visited;
    unordered_map<int, vector<int>> edges;
    bool path_exist = false;

    void dfs(int p) {
        if (p == goal)
            path_exist = true;
        for (int next: edges[p]) {
            if (!visited[next]) {
                dfs(next);
                if (path_exist) {
                    return;
                }
            } else if (visited[next] == 1) {
                path_exist = false;
                return;
            }
        }
        visited[p] = 2;
    }

public:
    bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start, int target) {
        goal = target;
        visited.resize(n);
        for (const vector<int> &edge: graph) {
            edges[edge[0]].push_back(edge[1]);
        }
        dfs(start);
        return path_exist;
    }
};