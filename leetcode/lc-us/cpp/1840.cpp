#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>> &r) {
        r.push_back({1, 0});
        sort(r.begin(), r.end());
        if (r.back()[0] != n) r.push_back({n, n - 1});
        n = (int) r.size();
        for (int i = 1; i < n; i++) {
            r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0]);
        }
        for (int i = n - 2; i >= 0; i--) {
            r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0]);
        }
        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max(res, (r[i][1] + r[i - 1][1] + r[i][0] - r[i - 1][0]) / 2);
        }
        return res;
    }
};