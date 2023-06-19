#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int> &nums) {
        int INF = 1e9;
        int f[3] = {0, -INF, -INF};
        for (int x: nums) {
            int g[3];
            memcpy(g, f, sizeof f);
            for (int i = 0; i < 3; i++) {
                g[i] = max(f[i], f[((i - x) % 3 + 3) % 3] + x);
            }
            memcpy(f, g, sizeof g);
        }
        return f[0];
    }
};