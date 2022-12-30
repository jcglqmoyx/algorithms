#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> cutSquares(vector<int> &s1, vector<int> &s2) {
        vector<double> res(4);
        double l1 = s1[2], l2 = s2[2];
        double x1 = s1[0] + l1 / 2, y1 = s1[1] + l1 / 2, x2 = s2[0] + l2 / 2, y2 = s2[1] + l2 / 2;
        if (x1 == x2) {
            res = {x1, min(s1[1] * 1.0, s2[1] * 1.0), x1, max(s1[1] + l1, s2[1] + l2)};
        } else {
            double slope = (y2 - y1) / (x2 - x1);
            double b = y1 - x1 * slope;
            if (fabs(slope) > 1.0) {
                res[1] = min(s1[1], s2[1]), res[3] = max(s1[1] + l1, s2[1] + l2);
                res[0] = (res[1] - b) / slope;
                res[2] = (res[3] - b) / slope;
            } else {
                res[0] = min(s1[0], s2[0]), res[2] = max(s1[0] + l1, s2[0] + l2);
                res[1] = slope * res[0] + b;
                res[3] = slope * res[2] + b;
            }
        }
        if (res[0] > res[2]) swap(res[0], res[2]), swap(res[1], res[3]);
        return res;
    }
};