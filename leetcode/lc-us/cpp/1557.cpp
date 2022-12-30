#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
        vector<int> starting_points;
        vector<bool> points(n, true);
        for (vector<int> &edge: edges) points[edge[1]] = false;
        for (int i = 0; i < n; i++) if (points[i]) starting_points.emplace_back(i);
        return starting_points;
    }
};