#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>> &grid) {
        using PII = pair<int, int>;
        int n = (int) grid.size(), m = (int) grid[0].size();
        vector<vector<PII>> s(n + 1, vector<PII>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x = grid[i - 1][j - 1];
                s[i][j].first = s[i - 1][j].first + s[i][j - 1].first - s[i - 1][j - 1].first;
                while (x % 2 == 0) {
                    s[i][j].first++;
                    x >>= 1;
                }
                s[i][j].second = s[i - 1][j].second + s[i][j - 1].second - s[i - 1][j - 1].second;
                while (x % 5 == 0) {
                    s[i][j].second++;
                    x /= 5;
                }
            }
        }
        auto get = [&](int x1, int y1, int x2, int y2, int idx) {
            if (idx == 0) return s[x2][y2].first - s[x1 - 1][y2].first - s[x2][y1 - 1].first + s[x1 - 1][y1 - 1].first;
            else return s[x2][y2].second - s[x1 - 1][y2].second - s[x2][y1 - 1].second + s[x1 - 1][y1 - 1].second;
        };
        auto get_top_left = [&](int i, int j) {
            int two = get(1, 1, i, j, 0) - get(1, 1, i - 1, j - 1, 0);
            int five = get(1, 1, i, j, 1) - get(1, 1, i - 1, j - 1, 1);
            return min(two, five);
        };
        auto get_bottom_left = [&](int i, int j) {
            int two = get(i, 1, n, j, 0) - get(i + 1, 1, n, j - 1, 0);
            int five = get(i, 1, n, j, 1) - get(i + 1, 1, n, j - 1, 1);
            return min(two, five);
        };
        auto get_top_right = [&](int i, int j) {
            int two = 0, five = 0;
            two += get(1, j, i, m, 0) - get(1, j + 1, i - 1, m, 0);
            five += get(1, j, i, m, 1) - get(1, j + 1, i - 1, m, 1);
            return min(two, five);
        };
        auto get_bottom_right = [&](int i, int j) {
            int two = 0, five = 0;
            two += get(i, j, n, m, 0) - get(i + 1, j + 1, n, m, 0);
            five += get(i, j, n, m, 1) - get(i + 1, j + 1, n, m, 1);
            return min(two, five);
        };
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                res = max(res, get_top_left(i, j));
                res = max(res, get_bottom_left(i, j));
                res = max(res, get_top_right(i, j));
                res = max(res, get_bottom_right(i, j));
            }
        }
        return res;
    }
};