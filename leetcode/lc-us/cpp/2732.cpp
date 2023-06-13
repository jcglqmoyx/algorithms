#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &g) {
        int n = (int) g.size(), m = (int) g[0].size();
        vector<int> res;
        int memo[1 << m];
        memset(memo, -1, sizeof memo);
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < m; j++) {
                if (g[i][j]) mask |= 1 << j;
            }
            int t = ((1 << m) - 1) ^ mask;
            for (int j = t; j; j = (j - 1) & t) {
                if (memo[j] != -1) return {memo[j], i};
            }
            if (!mask) return {i};
            memo[mask] = i;
        }
        return {};
    }
};