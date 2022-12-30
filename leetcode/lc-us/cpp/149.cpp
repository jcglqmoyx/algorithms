#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        using LD = long double;
        int res = 1;
        for (auto &p: points) {
            int ss = 0, vs = 0;
            unordered_map<LD, int> cnt;
            for (auto &q: points) {
                if (p == q) ss++;
                else if (p[0] == q[0]) vs++;
                else {
                    LD slope = (LD) (p[1] - q[1]) / (p[0] - q[0]);
                    cnt[slope]++;
                }
            }
            int c = vs;
            for (auto[k, v]: cnt) c = max(c, v);
            res = max(res, c + ss);
        }
        return res;
    }
};