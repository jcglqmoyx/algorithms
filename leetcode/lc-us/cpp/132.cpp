#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = (int) s.size(), INF = 1e9;
        vector<int> f(n + 1, INF);
        f[0] = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (is_palindrome(s, j - 1, i - 1)) {
                    f[i] = min(f[i], f[j - 1] + 1);
                }
            }
        }
        return f[n];
    }

private:
    inline bool is_palindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
};