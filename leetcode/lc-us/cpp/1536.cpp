#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>> &grid) {
        int n = (int) grid.size();
        for (auto &r: grid) {
            int cnt = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (!r[i]) cnt++;
                else break;
            }
            r[0] = cnt;
        }
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            int zero = n - i - 1;
            int j = i;
            while (j < n && grid[j][0] < zero) j++;
            if (j == n) return -1;
            res += j - i;
            while (j > i) {
                swap(grid[j], grid[j - 1]);
                j--;
            }
        }
        return res;
    }
};