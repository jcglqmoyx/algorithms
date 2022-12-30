#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        map<int, int> m;
        int n = (int) intervals.size();
        for (int i = 0; i < n; i++) {
            m[intervals[i][0]] = i;
        }
        vector<int> res;
        res.reserve(n);
        for (auto &interval: intervals) {
            auto p = m.lower_bound(interval[1]);
            if (p == m.end()) res.push_back(-1);
            else res.push_back(p->second);
        }
        return res;
    }
};