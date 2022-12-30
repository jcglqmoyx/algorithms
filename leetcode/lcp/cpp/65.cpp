#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int unSuitability(vector<int> &operate) {
        int mx = *max_element(operate.begin(), operate.end()) * 2 + 1;
        int pre[mx], f[mx];
        memset(pre, 0x3f, sizeof(pre));
        pre[0] = 0;
        for (int x: operate) {
            memset(f, 0x3f, sizeof(f));
            for (int j = 0; j < mx; ++j) {
                int dis = pre[j];
                if (dis == 0x3f3f3f3f) continue; // 无效的长度（无法组成）
                if (j + x < mx) f[j + x] = min(f[j + x], max(dis, j + x));
                if (j >= x) f[j - x] = min(f[j - x], dis);
                else f[0] = min(f[0], dis - j + x);
            }
            memcpy(pre, f, sizeof(f));
        }
        return *min_element(pre, pre + mx);
    }
};