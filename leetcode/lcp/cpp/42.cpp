#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int circleGame(vector<vector<int>> &toys, vector<vector<int>> &circles, int r) {
        using VI = vector<int>;
        int n = (int) circles.size();
        sort(circles.begin(), circles.end());
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            int x = circles[i][0], y = circles[i][1];
            map[x].push_back(y);
        }
        int cnt = 0;
        for (auto &t: toys) {
            int xi = t[0], yi = t[1], ri = t[2];
            if (ri > r) continue;
            int low = (int) (lower_bound(circles.begin(), circles.end(), VI{xi + ri - r, -1}) - circles.begin());
            bool found = false;
            for (int i = low; i < n; i++) {
                int x = circles[i][0];
                if (x > xi - ri + r) break;
                auto &v = map[x];
                int m = (int) v.size();
                int pos = (int) (lower_bound(v.begin(), v.end(), yi + ri - r) - v.begin());
                if (pos == m) continue;
                for (int j = pos; j < m; j++) {
                    int y = v[j];
                    if (y > yi - ri + r) break;
                    int dx = xi - x, dy = yi - y;
                    if ((double) dx * dx + (double) dy * dy <= pow(r - ri, 2)) {
                        found = true;
                        goto label;
                    }
                }
                i = (int) (upper_bound(circles.begin(), circles.end(), VI{x, INT32_MAX}) - circles.begin());
                i--;
            }
            label:
            if (found) {
                cnt++;
            }
        }
        return cnt;
    }
};