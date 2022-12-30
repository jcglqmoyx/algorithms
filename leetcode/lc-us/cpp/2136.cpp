#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int> &p, vector<int> &g) {
        int n = (int) p.size();
        vector<pair<int, int>> v;
        v.reserve(n);
        for (int i = 0; i < n; i++) {
            v.emplace_back(g[i], p[i]);
        }
        sort(v.begin(), v.end(), greater<>());
        int res = 0;
        int t1 = 0, t2 = 0;
        for (auto t: v) {
            t1 += t.second;
            t2 = max(t2, t1 + t.first);
        }
        return t2;
    }
};