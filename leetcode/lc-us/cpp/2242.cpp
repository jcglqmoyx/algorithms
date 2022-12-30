#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int> &scores, vector<vector<int>> &edges) {
        using PII = pair<int, int>;
        int n = (int) scores.size();
        vector<vector<PII>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].emplace_back(-scores[y], y);
            g[y].emplace_back(-scores[x], x);
        }
        for (auto &v: g) {
            if (v.size() >= 3) {
                nth_element(v.begin(), v.begin() + 2, v.end());
                v.resize(3);
            }
        }
        int res = -1;
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            int t = scores[x] + scores[y];
            for (auto a: g[x]) {
                int sa = a.first, pa = a.second;
                for (auto b: g[y]) {
                    int sb = b.first, pb = b.second;
                    if (pa != y && pb != x && pa != pb) {
                        res = max(res, t - sa - sb);
                    }
                }
            }
        }
        return res;
    }
};