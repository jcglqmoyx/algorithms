#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved) {
        vector<vector<int>> res;
        int n = (int) intervals.size();
        int x = toBeRemoved[0], y = toBeRemoved[1];
        for (int i = 0; i < n; i++) {
            int a = max(x, intervals[i][0]), b = min(y, intervals[i][1]);
            int len = b - a;
            if (len > 0) {
                if (len == intervals[i][1] - intervals[i][0]) {
                    continue;
                }
                if (len == y - x) {
                    if (intervals[i][0] < x) {
                        res.push_back({intervals[i][0], x});
                    }
                    if (intervals[i][1] > y) {
                        res.push_back({y, intervals[i][1]});
                    }
                } else if (a == x) {
                    res.push_back({intervals[i][0], x});
                } else {
                    res.push_back({y, intervals[i][1]});
                }
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};