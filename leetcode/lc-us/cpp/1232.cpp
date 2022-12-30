#include <bits/stdc++.h>

using namespace std;

class Solution {
    double get_slope(const vector<int> &a, const vector<int> &b) {
        return (double) (a[1] - b[1]) / (a[0] - b[0]);
    }

public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        if (coordinates[0][0] == coordinates[1][0]) {
            for (int i = 1; i < coordinates.size() - 1; i++) {
                if (coordinates[i][0] != coordinates[i + 1][0]) {
                    return false;
                }
            }
            return true;
        }
        double slope = get_slope(coordinates[0], coordinates[1]);
        for (int i = 1; i < coordinates.size() - 1; i++) {
            if (get_slope(coordinates[i], coordinates[i + 1]) != slope) {
                return false;
            }
        }
        return true;
    }
};