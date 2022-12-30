#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, int> degree;
        unordered_map<int, vector<int>> path;
        for (auto &p: prerequisites) {
            int x = p[0], y = p[1];
            degree[x]++;
            path[y].push_back(x);
        }
        vector<int> res;
        res.reserve(numCourses);
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                res.push_back(i);
                q.push(i);
            }
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int x: path[t]) {
                if (--degree[x] == 0) {
                    q.push(x);
                    res.push_back(x);
                }
            }
        }
        if (res.size() == numCourses) return res;
        else return {};
    }
};