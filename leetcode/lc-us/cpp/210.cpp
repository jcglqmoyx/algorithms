#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> res;
    bool valid = true;

    void dfs(int i) {
        visited[i] = 1;
        for (int j: edges[i]) {
            if (!visited[j]) {
                dfs(j);
                if (!valid) return;
            } else if (visited[j] == 1) {
                valid = false;
                return;
            }
        }
        visited[i] = 2;
        res.push_back(i);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const vector<int> &prerequisite: prerequisites) edges[prerequisite[1]].push_back(prerequisite[0]);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) dfs(i);
            if (!valid) return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};