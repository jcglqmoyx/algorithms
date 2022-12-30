#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        auto calc = [](int len) {
            if (len == 1) return 1;
            int res = 1;
            while (len) {
                res++;
                len /= 10;
            }
            return res;
        };
        int n = (int) s.size();
        int f[n + 1][n - k + 1];
        memset(f, 0x3f, sizeof f);
        f[n][n - k] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int cnt = 0; cnt <= n - k; cnt++) {
                for (int j = i, same = 0; j < n; j++) {
                    same += s[j] == s[i];
                    if (cnt + same > n - k) break;
                    f[i][cnt] = min(f[i][cnt], f[j + 1][cnt + same] + calc(same));
                }
                f[i][cnt] = min(f[i][cnt], f[i + 1][cnt]);
            }
        }
        return f[0][0];
    }
};