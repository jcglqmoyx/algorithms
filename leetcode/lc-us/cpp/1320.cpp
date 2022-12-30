#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDistance(string word) {
        int dist[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                } else if (i > j) {
                    dist[i][j] = dist[j][i];
                } else {
                    int r1 = i / 6, c1 = i % 6;
                    int r2 = j / 6, c2 = j % 6;
                    dist[i][j] = abs(r1 - r2) + abs(c1 - c2);
                }
            }
        }
        int n = (int) word.size();
        int f[n + 1][26][26];
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                f[0][i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            int idx = word[i - 1] - 'A';
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    f[i][j][k] = min(f[i][j][k], f[i - 1][idx][k] + dist[idx][j]);
                    f[i][j][k] = min(f[i][j][k], f[i - 1][j][idx] + dist[idx][k]);
                }
            }
        }
        int res = INT32_MAX;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                res = min(res, f[n][i][j]);
            }
        }
        return res;
    }
};