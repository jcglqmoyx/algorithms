#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
        const int N = 1e5 + 5;
        int sum[N][26];
        memset(sum, 0, sizeof sum);
        int n = (int) s.size();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                sum[i][j] = sum[i - 1][j] + (s[i - 1] - 'a' == j);
            }
        }
        vector<bool> res;
        res.reserve(queries.size());
        for (auto &q: queries) {
            int odd = 0;
            for (int i = 0; i < 26; i++) {
                if ((sum[q[1] + 1][i] - sum[q[0]][i]) & 1) {
                    odd++;
                }
            }
            if (odd > q[2] * 2 + 1) res.push_back(false);
            else res.push_back(true);
        }
        return res;
    }
};