#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fieldOfGreatestBlessing(vector<vector<int>> &forceField) {
        using LL = long long;
        vector<LL> vx, vy;
        for (auto &f: forceField) {
            LL r = f[2];
            for (int j = 0; j < 2; j++) {
                f[j] *= 2;
                vx.push_back(f[0] - r);
                vx.push_back(f[0] + r);
                vy.push_back(f[1] - r);
                vy.push_back(f[1] + r);
            }
        }
        sort(vx.begin(), vx.end());
        sort(vy.begin(), vy.end());
        vx.erase(unique(vx.begin(), vx.end()), vx.end());
        vy.erase(unique(vy.begin(), vy.end()), vy.end());
        auto get_x = [&](LL x) {
            return (int) (lower_bound(vx.begin(), vx.end(), x) - vx.begin() + 1);
        };
        auto get_y = [&](LL y) {
            return (int) (lower_bound(vy.begin(), vy.end(), y) - vy.begin() + 1);
        };
        static const int N = 405;
        int diff[N][N];
        memset(diff, 0, sizeof diff);
        for (auto &f: forceField) {
            LL r = f[2];
            int x1 = get_x((f[0] - r)), x2 = get_x(f[0] + r);
            int y1 = get_y((f[1] - r)), y2 = get_y(f[1] + r);
            diff[x1][y1]++;
            diff[x2 + 1][y1]--;
            diff[x1][y2 + 1]--;
            diff[x2 + 1][y2 + 1]++;
        }
        int res = 0;
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                res = max(res, diff[i][j]);
            }
        }
        return res;
    }
};