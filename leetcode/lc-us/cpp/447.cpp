#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>> &points) {
        int n = (int) points.size();
        if (n < 3) return 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> map;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                map[dist(points[i], points[j])]++;
            }
            for (const auto &x: map) {
                count += x.second * (x.second - 1);
            }
        }
        return count;
    }

    int dist(const vector<int> &p1, const vector<int> &p2) {
        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];
        return x * x + y * y;
    }
};