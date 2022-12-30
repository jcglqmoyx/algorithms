#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end());
        int arrows = 0;
        int n = (int) points.size();
        for (int i = 0; i < n;) {
            arrows++;
            int end = points[i][1];
            int j = i + 1;
            for (; j < n; j++) {
                end = min(end, points[j][1]);
                if (points[j][0] > end) {
                    break;
                }
            }
            i = j;
        }
        return arrows;
    }
};