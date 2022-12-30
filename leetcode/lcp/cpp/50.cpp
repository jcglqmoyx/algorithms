#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int giveGem(vector<int> &gem, vector<vector<int>> &operations) {
        for (auto &op: operations) {
            int x = op[0], y = op[1];
            gem[y] += gem[x] / 2;
            gem[x] -= gem[x] / 2;
        }
        int mn = INT32_MAX, mx = INT32_MIN;
        for (int cnt: gem) {
            mn = min(mn, cnt);
            mx = max(mx, cnt);
        }
        return mx - mn;
    }
};