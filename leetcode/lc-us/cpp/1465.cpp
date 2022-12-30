#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;
    const int MOD = 1e9 + 7;
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        int max_h = 0, max_w = 0, prev_h = 0, prev_w = 0;
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for (int cut: horizontalCuts) {
            max_h = max(max_h, cut - prev_h);
            prev_h = cut;
        }
        for (int cut: verticalCuts) {
            max_w = max(max_w, cut - prev_w);
            prev_w = cut;
        }
        return (int) ((LL) max_h * max_w % MOD);
    }
};