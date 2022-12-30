#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>> &buildings) {
        map<int, int> diff, cnt;
        for (auto &b: buildings) {
            int x = b[0], y = b[1], h = b[2];
            diff[x] += h, diff[y] -= h;
            cnt[x]++, cnt[y]--;
        }
        int last = 0, k = 0;
        long long h = 0;
        vector<vector<int>> res;
        for (auto[pos, dt]: diff) {
            if (h) {
                long long avg = h / k;
                if (!res.empty() && res.back()[2] == avg && res.back()[1] == last) {
                    res.back()[1] = pos;
                } else {
                    res.push_back({last, pos, (int) avg});
                }
            }
            last = pos;
            k += cnt[pos];
            h += dt;
        }
        return res;
    }
};