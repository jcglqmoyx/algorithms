#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get_distance(vector<int> &s, vector<int> &t) {
        return abs(s[0] - t[0]) + abs(s[1] - t[1]);
    }

public:
    int minDistance(int height, int width, vector<int> &tree, vector<int> &squirrel, vector<vector<int>> &nuts) {
        int res = 0, max_diff = INT32_MIN;
        for (auto &nut: nuts) {
            int d1 = get_distance(nut, tree), d2 = get_distance(nut, squirrel);
            if (d1 - d2 > max_diff) max_diff = d1 - d2;
            res += d1 * 2;
        }
        return res - max_diff;
    }
};