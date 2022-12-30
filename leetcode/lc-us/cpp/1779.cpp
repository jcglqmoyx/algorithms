#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dist(int x, int y, const vector<int> point) {
        return abs(x - point[0]) + abs(y - point[1]);
    }

public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
        int min_dist = 1e9;
        int res = -1;
        for (int i = 0; i < points.size(); i++) {
            int distance = dist(x, y, points[i]);
            if ((x == points[i][0] || y == points[i][1]) && distance < min_dist) {
                min_dist = distance;
                res = i;
            }
        }
        return res;
    }
};