#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int matrixMedian(vector<vector<int>> &grid) {
        int m = (int) grid.size(), n = (int) grid[0].size();
        int tot = m * n;
        int left = 1, right = 1e6;
        while (left < right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                int lo = 0, hi = n;
                while (lo < hi) {
                    int mi = (lo + hi) >> 1;
                    if (grid[i][mi] > mid) hi = mi;
                    else lo = mi + 1;
                }
                cnt += lo;
            }
            if (cnt * 2 < tot) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};