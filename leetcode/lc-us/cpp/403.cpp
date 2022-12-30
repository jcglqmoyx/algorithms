#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canCross(vector<int> &stones) {
        int n = (int) stones.size();
        vector<vector<bool>> f(n, vector<bool>(n));
        f[0][0] = true;
        for (int i = 1; i < n; i++) {
            if (stones[i] - stones[i - 1] > i) return false;
            for (int j = i - 1; j >= 0; j--) {
                int dist = stones[i] - stones[j];
                if (dist > j + 1) break;
                if (f[j][dist - 1] || f[j][dist] || f[j][dist + 1]) {
                    f[i][dist] = true;
                    if (i == n - 1) return true;
                }
            }
        }
        return false;
    }
};