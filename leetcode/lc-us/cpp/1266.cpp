#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points) {
        int time = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            int x_diff = abs(points[i + 1][0] - points[i][0]);
            int y_diff = abs(points[i + 1][1] - points[i][1]);
            time += max(x_diff, y_diff);
        }
        return time;
    }
};