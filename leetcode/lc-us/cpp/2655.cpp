#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>> &ranges) {
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> res;
        int l, r = 0;
        for (int i = 0, end; i < ranges.size(); i++) {
            end = ranges[i][1];
            int j = i + 1;
            while (j < ranges.size() && ranges[j][0] <= end) end = max(end, ranges[j][1]), j++;
            if (r < ranges[i][0]) res.push_back({l, ranges[i][0] - 1});
            l = r = end + 1;
            i = j - 1;
        }
        if (r < n) res.push_back({l, n - 1});
        return res;
    }
};