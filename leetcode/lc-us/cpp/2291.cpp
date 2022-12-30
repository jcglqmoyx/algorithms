#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumProfit(vector<int> &present, vector<int> &future, int budget) {
        int n = (int) present.size();
        int p[n][2], cnt = 0;
        for (int i = 0; i < n; i++) {
            if (present[i] < future[i]) {
                p[cnt][0] = future[i] - present[i];
                p[cnt][1] = present[i];
                cnt++;
            }
        }
        int f[budget + 1];
        memset(f, 0, sizeof f);
        for (int i = 0; i < cnt; i++) {
            for (int j = budget; j >= p[i][1]; j--) {
                f[j] = max(f[j], f[j - p[i][1]] + p[i][0]);
            }
        }
        return f[budget];
    }
};