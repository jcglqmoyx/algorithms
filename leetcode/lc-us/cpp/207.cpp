#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> edges;
    bool valid = true;
    vector<int> visited;

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
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto &prerequisite: prerequisites) {
            edges[prerequisite[0]].push_back(prerequisite[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!valid) break;
            dfs(i);
        }
        return valid;
    }
};