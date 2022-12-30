#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles) {
        using LL = long long;
        unordered_map<double, LL> hash;
        for (auto &r: rectangles) hash[(double) r[0] / r[1]]++;
        LL res = 0;
        for (auto &[num, cnt]: hash) res = (res + cnt * (cnt - 1) / 2);
        return res;
    }
};