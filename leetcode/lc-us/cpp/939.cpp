#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>> &points) {
        unordered_set<int> s;
        for (auto &p: points) s.insert(p[0] * 50000 + p[1]);
        int res = INT32_MAX;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                auto &p = points[i], &q = points[j];
                if (p[0] != q[0] && p[1] != q[1] &&
                    s.count(p[0] * 50000 + q[1]) && s.count(q[0] * 50000 + p[1])) {
                    res = min(res, abs(p[1] - q[1]) * abs(p[0] - q[0]));
                }
            }
        }
        if (res == INT32_MAX) return 0;
        return res;
    }
};