#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDayskVariants(vector<vector<int>> &points, int k) {
        vector<pair<int, int>> new_points;
        for (auto &p: points) {
            new_points.emplace_back(p[0] + p[1], p[1] - p[0]);
        }
        sort(new_points.begin(), new_points.end());
        auto check = [&](int t) {
            map<int, int> m;
            int pos = 0;
            for (auto&&[x, y]: new_points) {
                m[y]++;
                while (x - new_points[pos].first > 2 * t) {
                    m[new_points[pos].second]--;
                    pos++;
                }
                for (auto i = m.begin(); i != m.end(); ++i) {
                    auto cur = m.upper_bound(i->first + 2 * t);
                    int cnt = 0;
                    for (auto j = i; j != cur; ++j) cnt += j->second;
                    if (cnt >= k && !((x + i->first) % 2 && 2 * t == x - new_points[pos].first && (--cur)->first - 2 * t == i->first)) {
                        return true;
                    }
                }
            }
            return false;
        };

        int l = 0, r = 1e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};