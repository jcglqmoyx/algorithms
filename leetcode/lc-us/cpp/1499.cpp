#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k) {
        int res = INT32_MIN;
        deque<int> q;
        for (int i = 0, j = 0; j < points.size(); j++) {
            while (!q.empty() && points[j][0] - points[q.front()][0] > k) {
                if (i == q.front()) q.pop_front();
                i++;
            }
            if (!q.empty() && j != q.front()) {
                res = max(res, points[j][0] + points[j][1] + points[q.front()][1] - points[q.front()][0]);
            }
            while (!q.empty() && points[q.back()][1] - points[q.back()][0] <= points[j][1] - points[j][0]) {
                q.pop_back();
            }
            q.push_back(j);
        }
        return res;
    }
};