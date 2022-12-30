#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dist(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }

public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries) {
        int n = (int) queries.size();
        vector<int> res;
        res.reserve(n);
        for (vector<int> &q: queries) {
            int cnt = 0;
            for (vector<int> &p: points) {
                if (dist(p[0], p[1], q[0], q[1]) <= q[2] * q[2]) {
                    cnt++;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};