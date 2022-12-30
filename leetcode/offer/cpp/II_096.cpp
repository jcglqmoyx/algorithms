#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = (int) s1.size(), n = (int) s2.size(), p = (int) s3.size();
        if (m + n != p) return false;
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
        f[0][0] = true;
        for (int i = 1; i <= m; i++) {
            if (s1[i - 1] == s3[i - 1]) f[i][0] = f[i - 1][0];
        }
        for (int i = 1; i <= n; i++) {
            if (s2[i - 1] == s3[i - 1]) f[0][i] = f[0][i - 1];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int k = i + j - 1;
                if (s1[i - 1] == s3[k]) f[i][j] = f[i][j] | f[i - 1][j];
                if (s2[j - 1] == s3[k]) f[i][j] = f[i][j] | f[i][j - 1];
            }
        }
        return f[m][n];
    }
};