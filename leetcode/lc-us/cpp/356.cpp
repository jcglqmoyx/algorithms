#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isReflected(vector<vector<int>> &points) {
        static constexpr int INF = 1e9;
        int mn = INF, mx = -INF;
        set<pair<int, int>> s;
        for (auto &p: points) {
            mn = min(mn, p[0]), mx = max(mx, p[0]);
            s.insert({p[0], p[1]});
        }
        int sum = mn + mx;
        for (auto &p: points) {
            int x = p[0], y = p[1];
            if (x * 2 >= sum || !s.count({x, y})) continue;
            if (!s.count({sum - x, y})) return false;
            else s.erase({sum - x, y}), s.erase({x, y});
        }
        return all_of(s.begin(), s.end(), [&](pair<int, int> p) {
            return p.first * 2 <= sum;
        });
    }
};