#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int l1 = (int) word1.size(), l2 = (int) word2.size();
        string s = word1 + word2;
        int n = l1 + l2;
        int f[n][n];
        memset(f, 0, sizeof f);
        int res = 0;
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (len == 1) {
                    f[i][j] = 1;
                } else {
                    if (s[i] == s[j]) {
                        f[i][j] = f[i + 1][j - 1] + 2;
                        if (i < l1 && j >= l1) res = max(res, f[i][j]);
                    }
                    f[i][j] = max(f[i][j], max(f[i + 1][j], f[i][j - 1]));
                }
            }
        }
        return res;
    }
};