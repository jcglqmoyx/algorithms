#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>> &points) {
        using LL = long long;
        int n = (int) points.size(), m = (int) points[0].size();
        vector<LL> f(m);
        for (int j = 0; j < m; j++) f[j] = points[0][j];
        for (int i = 1; i < n; i++) {
            vector<LL> l(m), r(m);
            LL mx = INT64_MIN;
            for (int j = 0; j < m; j++) mx = max(mx, f[j] + j), l[j] = mx;
            mx = INT64_MIN;
            for (int j = m - 1; ~j; j--) mx = max(mx, f[j] - j), r[j] = mx;
            for (int j = 0; j < m; j++) f[j] = points[i][j] + max(l[j] - j, r[j] + j);
        }
        return *max_element(f.begin(), f.end());
    }
};