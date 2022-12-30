#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
        int x = target[0], y = target[1], z = target[2];
        int mx = 0, my = 0, mz = 0;
        for (auto &t: triplets) {
            int a = t[0], b = t[1], c = t[2];
            if (a <= x && b <= y && c <= z) {
                mx = max(mx, a);
                my = max(my, b);
                mz = max(mz, c);
            }
        }
        return mx == x && my == y && mz == z;
    }
};