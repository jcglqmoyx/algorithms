#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        bool used = false;
        int left = newInterval[0], right = newInterval[1];
        for (vector<int> &interval: intervals) {
            if (interval[0] > right) {
                if (!used) {
                    res.push_back({left, right});
                    used = true;
                }
                res.push_back(interval);
            } else if (interval[1] < left) res.push_back(interval);
            else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!used) res.push_back({left, right});
        return res;
    }
};