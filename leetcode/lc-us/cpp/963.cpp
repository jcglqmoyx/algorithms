#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

    LL get(vector<int> &a, vector<int> &b) {
        LL dx = a[0] - b[0], dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }

public:
    double minAreaFreeRect(vector<vector<int>> &p) {
        const double INF = 1e20;
        double res = INF;
        int n = (int) p.size();
        vector<vector<LL>> v;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                v.push_back({p[i][0] + p[j][0], p[i][1] + p[j][1], get(p[i], p[j]), i, j});
            }
        }
        sort(v.begin(), v.end());
        n = (int) v.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && v[j][0] == v[i][0] && v[j][1] == v[i][1] && v[j][2] == v[i][2]) {
                j++;
            }
            for (int a = i; a < j; a++) {
                for (int b = a + 1; b < j; b++) {
                    if (v[a][3] != v[b][3]) {
                        res = min(res, sqrt(get(p[v[a][3]], p[v[b][3]])) * sqrt(get(p[v[a][4]], p[v[b][3]])));
                    }
                }
            }
            i = j - 1;
        }
        return res == INF ? 0 : res;
    }
};