#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = (int) s.size();
        int f[n + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            if (i >= k) {
                for (int j = i - k; j >= 0; j--) {
                    if (valid(s, j, i)) {
                        f[i] = max(f[i], f[j] + 1);
                        break;
                    }
                    int tot = f[i] * k;
                    if (i - tot < k) break;
                }
            }
        }
        return f[n];
    }

private:
    bool valid(string &s, int a, int b) {
        b--;
        while (a < b) {
            if (s[a] != s[b]) return false;
            a++, b--;
        }
        return true;
    }
};