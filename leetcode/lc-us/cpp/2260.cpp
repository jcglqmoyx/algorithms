#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int> &v) {
        int res = 1e8;
        int n = (int) v.size();
        int f[1000010];
        memset(f, -1, sizeof f);
        for (int i = 0; i < n; i++) {
            int x = v[i];
            if (f[x] != -1) {
                res = min(i - f[x] + 1, res);
            }
            f[x] = i;
        }
        return res == 1e8 ? -1 : res;
    }
};