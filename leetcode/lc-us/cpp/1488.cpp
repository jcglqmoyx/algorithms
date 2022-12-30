#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int> &rains) {
        int n = (int) rains.size();
        vector<int> res(n, 1);
        unordered_map<int, int> pre;
        set<int> dry;
        for (int i = 0; i < n; i++) {
            int idx = rains[i];
            if (!idx) {
                dry.insert(i);
                continue;
            }
            if (pre.count(idx)) {
                auto it = dry.upper_bound(pre[idx]);
                if (it == dry.end()) return {};
                res[*it] = idx;
                dry.erase(it);
            }
            pre[idx] = i;
            res[i] = -1;
        }
        return res;
    }
};