#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int low = intervals[0][0], high = intervals[0][1];
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (high >= intervals[i + 1][0]) high = max(high, intervals[i + 1][1]);
            else {
                res.push_back({low, high});
                low = intervals[i + 1][0];
                high = intervals[i + 1][1];
            }
        }
        res.push_back({low, high});
        return res;
    }
};