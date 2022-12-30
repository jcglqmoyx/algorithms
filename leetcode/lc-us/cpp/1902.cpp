#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDepthBST(vector<int> &order) {
        map<int, int> m;
        m[0] = 0;
        int res = 1;
        for (int x: order) {
            auto it = m.upper_bound(x);
            int t = it->second;
            it--;
            t = max(t, it->second);
            res = max(res, t + 1);
            m[x] = t + 1;
        }
        return res;
    }
};