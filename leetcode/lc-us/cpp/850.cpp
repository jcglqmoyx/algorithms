#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    using LL = long long;
    using PII = pair<int, int>;

    LL calc(vector<vector<int>> &rectangles, int l, int r) {
        vector<PII> v;
        for (auto rect: rectangles) {
            if (rect[0] <= l && rect[2] >= r) {
                v.emplace_back(rect[1], rect[3]);
            }
        }
        sort(v.begin(), v.end());

        LL res = 0, start = -1, end = -1;
        for (auto &seg: v) {
            if (seg.first > end) {
                res += end - start;
                start = seg.first, end = seg.second;
            } else if (seg.second > end) {
                end = seg.second;
            }
        }
        res += end - start;
        return res * (r - l);
    }

public:
    int rectangleArea(vector<vector<int>> &rectangles) {
        const int MOD = 1e9 + 7;
        vector<int> xs;
        for (auto r: rectangles) {
            xs.emplace_back(r[0]);
            xs.emplace_back(r[2]);
        }
        sort(xs.begin(), xs.end());
        LL res = 0;
        for (int i = 1; i < xs.size(); i++) {
            res += calc(rectangles, xs[i - 1], xs[i]);
        }
        return (int) (res % MOD);
    }
};