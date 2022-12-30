#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int defendSpaceCity(vector<int> &time, vector<int> &position) {
        int n = *max_element(position.begin(), position.end());
        int m = 1 << *max_element(time.begin(), time.end());
        int rain[n + 1];
        memset(rain, 0, sizeof(rain));
        for (int i = 0; i < time.size(); ++i) {
            rain[position[i]] |= 1 << (time[i] - 1);
        }

        int un[m], single[m];
        un[0] = single[0] = 0;
        for (int i = 1; i < m; ++i) {
            int lb = i & -i, j = i ^ lb, lb2 = j & -j;
            un[i] = un[j] + (lb == (lb2 >> 1) ? 1 : 3);
            single[i] = single[j] + (lb == (lb2 >> 1) ? 1 : 2);
        }

        int f[n + 1][m];
        memset(f, 0x3f, sizeof(f));
        for (int j = 0; j < m; ++j) {
            f[0][j] = un[j] + single[((m - 1) ^ j) & rain[0]];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int mask = (m - 1) ^ j, pre = mask;; pre = (pre - 1) & mask) {
                    int cost = f[i - 1][pre] + un[j] + single[(mask ^ pre) & rain[i]];
                    f[i][j] = min(f[i][j], cost);
                    if (pre == 0) break;
                }
            }
        }
        return f[n][0];
    }
};