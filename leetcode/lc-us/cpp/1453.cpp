#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numPoints(vector<vector<int>> &points, int r) {
        const double PI = acos(-1);
        if (points.empty()) return 0;
        int n = (int) points.size();
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            vector<pair<double, double>> items;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                double xjxi = points[j][0] - points[i][0];
                double yjyi = points[j][1] - points[i][1];
                double dij = sqrt(xjxi * xjxi + yjyi * yjyi);
                if (dij > 2 * r + 1e-6) continue;
                double a = atan(yjyi / xjxi);
                if (xjxi < 0) a = (yjyi > 0) ? a + PI : a - PI;
                double b = acos(dij / (r * 2));
                items.emplace_back(a - b, -1);
                items.emplace_back(a + b, 1);
            }
            sort(items.begin(), items.end());
            int cnt = 1;
            for (auto &p: items) {
                cnt -= (int) p.second;
                if (cnt > ans) ans = cnt;
            }
        }
        return ans;
    }
};