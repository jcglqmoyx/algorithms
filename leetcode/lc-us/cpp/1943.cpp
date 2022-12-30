#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments) {
        using LL = long long;
        vector<vector<int>> points;
        for (auto &seg: segments) {
            points.push_back({seg[0], seg[2]});
            points.push_back({seg[1], -seg[2]});
        }
        sort(points.begin(), points.end());
        vector<vector<LL>> res;
        LL tot = points[0][1];
        for (int i = 1; i < (int) points.size(); i++) {
            if (points[i][0] != points[i - 1][0] && tot) {
                res.push_back({points[i - 1][0], points[i][0], tot});
            }
            tot += points[i][1];
        }
        return res;
    }
};