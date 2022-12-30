#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts) {
        int cost = 0;
        int x1 = startPos[0], y1 = startPos[1];
        int x2 = homePos[0], y2 = homePos[1];
        if (x1 < x2) {
            for (int r = x1 + 1; r <= x2; r++) cost += rowCosts[r];
        } else if (x1 > x2) {
            for (int r = x1 - 1; r >= x2; r--) cost += rowCosts[r];
        }
        if (y1 < y2) {
            for (int c = y1 + 1; c <= y2; c++) cost += colCosts[c];
        } else if (y1 > y2) {
            for (int c = y1 - 1; c >= y2; c--) cost += colCosts[c];
        }
        return cost;
    }
};