#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        int n = (int) intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            while (i < n && res.back()[1] >= intervals[i][0]) res.back()[1] = max(res.back()[1], intervals[i][1]), i++;
            if (i < n) res.push_back(intervals[i]);
        }
        return res;
    }
};