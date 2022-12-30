#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        LL min_x = INF, min_y = INF, max_x = -INF, max_y = -INF;
        LL total_area = 0;
        for (auto &r: rectangles) {
            LL x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
            min_x = min(min_x, x1);
            min_y = min(min_y, y1);
            max_x = max(max_x, x2);
            max_y = max(max_y, y2);
            add(x1, y1), add(x1, y2), add(x2, y1), add(x2, y2);
            total_area += (x2 - x1) * (y2 - y1);
        }
        if (total_area != (max_x - min_x) * (max_y - min_y)) return false;
        if (cnt[to_string(min_x) + ' ' + to_string(min_y)] != 1) return false;
        if (cnt[to_string(min_x) + ' ' + to_string(max_y)] != 1) return false;
        if (cnt[to_string(max_x) + ' ' + to_string(min_y)] != 1) return false;
        if (cnt[to_string(max_x) + ' ' + to_string(max_y)] != 1) return false;
        int count_points_occurred_once = 0;
        for (auto[k, v]: cnt) {
            if (v == 1) count_points_occurred_once++;
            else if (v != 2 && v != 4) return false;
        }
        return count_points_occurred_once == 4;
    }

private:
    using LL = long long;
    const LL INF = 1e5 + 1, F = INF + 1;
    unordered_map<string, int> cnt;

    void add(LL x, LL y) {
        cnt[to_string(x) + ' ' + to_string(y)]++;
    }
};