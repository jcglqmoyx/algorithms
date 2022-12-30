#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points) {
        vector<int> x_coordinates;
        x_coordinates.reserve(points.size());
        for (const vector<int> &point: points) {
            x_coordinates.push_back(point[0]);
        }
        sort(x_coordinates.begin(), x_coordinates.end());
        int max_wid = 0;
        for (int i = 0; i < x_coordinates.size() - 1; i++) {
            max_wid = max(max_wid, x_coordinates[i + 1] - x_coordinates[i]);
        }
        return max_wid;
    }
};