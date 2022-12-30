#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0};
        vector<int> degree(n);
        unordered_map<int, vector<int>> neighbors;
        for (const vector<int> &edge: edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (n - q.size()) {
            int size = q.size();
            n -= size;
            while (size--) {
                int point = q.front();
                q.pop();
                degree[point]--;
                for (int neighbor: neighbors[point]) {
                    if (degree[neighbor] > 1) {
                        degree[neighbor]--;
                        if (degree[neighbor] == 1) {
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};