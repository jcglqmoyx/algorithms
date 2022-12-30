#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        string t;
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) j++;
            t.push_back(s[i]);
            i = j - 1;
        }
        n = (int) t.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (i == j) f[i][j] = 1;
                else {
                    if (t[i] == t[j]) {
                        f[i][j] = f[i][j - 1];
                    } else {
                        f[i][j] = 1e8;
                        for (int k = i; k < j; k++) {
                            f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
                        }
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};