#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isConvex(vector<vector<int>> &points) {
        using LL = long long;
        LL prev = 0;
        int n = (int) points.size();
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0] - points[(i + 1) % n][0];
            int y1 = points[i][1] - points[(i + 1) % n][1];
            int x2 = points[(i + 1) % n][0] - points[(i + 2) % n][0];
            int y2 = points[(i + 1) % n][1] - points[(i + 2) % n][1];
            LL product = x1 * y2 - x2 * y1;
            if (product) {
                if (prev * product < 0) return false;
                prev = product;
            }
        }
        return true;
    }
};