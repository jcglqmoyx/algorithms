#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int perfectMenu(vector<int> &materials, vector<vector<int>> &cookbooks, vector<vector<int>> &attribute, int limit) {
        int n = (int) cookbooks.size();
        int res = -1;
        for (int state = 1; state < 1 << n; state++) {
            int s = 0, t = 0;
            vector<int> m = materials;
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (state >> i & 1) {
                    for (int j = 0; j < 5; j++) {
                        if (m[j] < cookbooks[i][j]) {
                            ok = false;
                            goto label;
                        }
                        m[j] -= cookbooks[i][j];
                    }
                    s += attribute[i][0];
                    t += attribute[i][1];
                }
            }
            label:
            if (ok && t >= limit) res = max(res, s);
        }
        return res;
    }
};