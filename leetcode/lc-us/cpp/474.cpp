#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        for (string &str: strs) {
            int zero = 0, one = 0;
            for (char c: str) {
                if (c == '0') zero++;
                else one++;
            }
            for (int i = m; i >= zero; i--) {
                for (int j = n; j >= one; j--) {
                    f[i][j] = max(f[i][j], f[i - zero][j - one] + 1);
                }
            }
        }
        return f[m][n];
    }
};