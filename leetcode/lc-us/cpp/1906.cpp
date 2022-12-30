#include <bits/stdc++.h>

using namespace std;

class Solution {
    static const int N = 1e5 + 5, M = 105;
    int s[N][M];
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
        int n = (int) nums.size(), m = (int) queries.size();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 100; j++) {
                int t = 0;
                if (nums[i - 1] == j) t = 1;
                s[i][j] = s[i - 1][j] + t;
            }
        }
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1] + 1;
            int min_diff = M;
            int prev = -1;
            for (int j = 1; j <= 100; j++) {
                int k = s[r][j] - s[l][j];
                if (k) {
                    if (prev != -1) {
                        int diff = j - prev;
                        if (diff) min_diff = min(min_diff, j - prev);
                    }
                    prev = j;
                }
                if (min_diff != M) res[i] = min_diff;
                else res[i] = -1;
            }
        }
        return res;
    }
};