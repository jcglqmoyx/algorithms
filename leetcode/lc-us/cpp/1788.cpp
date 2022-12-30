#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int> &flowers) {
        int n = (int) flowers.size();
        int sp[n + 1];
        sp[0] = 0;
        for (int i = 1; i <= n; i++) {
            sp[i] = sp[i - 1];
            if (flowers[i - 1] > 0) {
                sp[i] += flowers[i - 1];
            }
        }
        unordered_map<int, int> m;
        int res = INT32_MIN;
        for (int i = n; i; i--) {
            int f = flowers[i - 1];
            if (m.count(f)) continue;
            m[f] = i;
        }
        for (int i = 1; i < n; i++) {
            int f = flowers[i - 1];
            if (!m.count(f) || m[f] == i) continue;
            res = max(res, sp[m[f] - 1] - sp[i] + f * 2);
            m.erase(f);
        }
        return res;
    }
};