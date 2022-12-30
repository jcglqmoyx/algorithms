#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location) {
        int same_cnt = 0;
        vector<double> angles;
        int x = location[0], y = location[1];
        for (auto &p: points) {
            int a = p[0], b = p[1];
            if (a == x && b == y) same_cnt++;
            else {
                angles.push_back(atan2(b - y, a - x));
            }
        }
        sort(angles.begin(), angles.end());
        int n = (int) angles.size();
        for (int i = 0; i < n; i++) {
            angles.push_back(angles[i] + M_PI * 2);
        }
        int cnt = 0, j = 0;
        double r = angle / 180.0 * M_PI;
        for (int i = 0; i < n; i++) {
            while (j < (n << 1) && angles[j] <= angles[i] + r) j++;
            cnt = max(cnt, j - i);
        }
        return cnt + same_cnt;
    }
};