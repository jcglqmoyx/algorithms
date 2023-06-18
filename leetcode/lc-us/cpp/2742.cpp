#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int paintWalls(vector<int> &cost, vector<int> &time) {
        int n = (int) cost.size(), f[n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int c = cost[i], t = time[i] + 1;
            for (int j = n; j; j--) {
                f[j] = min(f[j], f[max(j - t, 0)] + c);
            }
        }
        return f[n];
    }
};