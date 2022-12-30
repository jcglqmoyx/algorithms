#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2) {
        int res = 0, n = (int) img1.size();
        for (int i = 1 - n; i < n; i++) {
            for (int j = 1 - n; j < n; j++) {
                int cnt = 0;
                for (int x = max(i, 0); x < min(i + n, n); x++) {
                    for (int y = max(0, j); y < min(j + n, n); y++) {
                        if (img1[x - i][y - j] && img2[x][y]) {
                            cnt++;
                        }
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};